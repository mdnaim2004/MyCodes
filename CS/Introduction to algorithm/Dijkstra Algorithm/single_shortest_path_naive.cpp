#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = INT_MAX;

vector<pair<int, int>> adj_list[N];
int dis[N];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        pair<int, int> par = pq.top();
        pq.pop();

        int par_dis = par.first;
        int par_node = par.second;

        // Ignore outdated entries
        if (par_dis > dis[par_node]) continue;

        for (auto child : adj_list[par_node]) {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node]) {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c}); // remove this if graph is directed
    }

    for (int i = 0; i < n; i++) {
        dis[i] = INF;
    }

    int src;
    cin >> src;

    dijkstra(src);

    for (int i = 0; i < n; i++) {
        cout << i << " => ";
        if (dis[i] == INF)
            cout << "INF";
        else
            cout << dis[i];
        cout << endl;
    }

    return 0;
}

/*
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5
file:///home/mdnaim2004/Downloads/graph.png
*/