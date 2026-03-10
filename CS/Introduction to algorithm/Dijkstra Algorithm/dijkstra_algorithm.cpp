#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[1005];
int dis[1005];

void dijkstra(int src){

}

int main(){
    int n, e;
    cin >> n >> e;

    //vector<pair<int, int>> adj_list[n];

    while(e--){
        int a,b,c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});

    }
    //memset(dis, INT_MAX, sizeof(dis));
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }
    dijkstra(0);

    return 0;
}