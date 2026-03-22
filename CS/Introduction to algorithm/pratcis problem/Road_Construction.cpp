#include<bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];

int cmp, mx;

int find(int node){
    if(par[node] == -1)
        return node;

    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2)
        return;

    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp--;
}

int main(){


    int n, e;
    cin >> n >> e;

    cmp = n;

    mx = 1;

    // memset(par, -1, sizeof(par));
    // memset(group_size, 1, sizeof(group_size));

    // for memset of opposit version.....

    for(int i=1; i<=n; i++){
        par[i] = -1;
        group_size[i] = 1;
    }

    while(e--){
        int a, b;
        cin >> a >> b;

        dsu_union(a,b); // dsu union ke pathano 
        cout << cmp << " " << mx << endl;

    }

    // for(int i=1; i<=n; i++){
    //     cout << i << " " << par[i] << " " << group_size[i]<< endl;
    // }
    return 0;
}