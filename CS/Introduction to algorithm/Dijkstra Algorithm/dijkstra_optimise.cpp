#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[1000];
int dis[1000];

void dijkstra(int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

}

int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;

    dijkstra(src);

    for (int i = 0; i < n; i++) {
        cout << i << " => " << dis[i];
        
        cout << endl;
    }
    return 0;
}