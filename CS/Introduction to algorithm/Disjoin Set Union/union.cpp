#include<bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

//find operation....
int find(int node){
    cout << node << endl;
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;

    return leader;
}

void dsu_union(int node1, int node2){

    int leader1 = find(node1);
    int leader2 = find(node2);

    if(group_size[leader1] > group_size[leader2]){
        par[leader2] = leader1;
    }
}

int main(){
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));


    dsu_union(1,2);

    cout << find(4) << endl;
    return 0;
}