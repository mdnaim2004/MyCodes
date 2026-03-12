#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[1005];// adjacency list to represent the graph, where each node has a list of pairs (child node, distance to child node)
int dis[1005];// array to store the shortest distance from the source node to each node in the graph

void dijkstra(int src){ // function to perform Dijkstra's algorithm starting from the source node
    queue<pair<int, int>> q;   // create a queue to store the nodes and their distances from the source node
    q.push({src, 0});// add the source node to the queue with distance 0 from itself
    dis[src] = 0;//add the source node to the queue with distance 0 from itself

    while(!q.empty()){// while the queue is not empty
        pair<int, int> par = q.front();// parent node and its distance from the source node
        q.pop();// remove the parent node from the queue

        int par_node = par.first;// parent node
        int par_dis = par.second; // distance of the parent node from the source node

        for(auto child : adj_list[par_node]){// loop through the child nodes of the parent node
            int child_node = child.first;// child node
            int child_dis = child.second; // distance of the child node from the parent node


        }
        
    }
}

int main(){// main function to read the graph information and call the Dijkstra's algorithm
    int n, e;// number of nodes and edges in the graph
    cin >> n >> e;// read the number of nodes and edges in the graph

    //vector<pair<int, int>> adj_list[n];

    while(e--){// loop to read the edge information and build the adjacency list
        int a,b,c;// variables to store the edge information (nodes a and b, and the weight c of the edge between them)
        cin >> a >> b >> c;// read the edge information (nodes a and b, and the weight c of the edge between them)

        adj_list[a].push_back({b,c}); // add the edge to the adjacency list for node a
        adj_list[b].push_back({a,c});// add the edge to the adjacency list for node b (since the graph is undirected)

    }
    //memset(dis, INT_MAX, sizeof(dis));
    for(int i=0; i<n; i++){// initialize the distance array with infinity
        dis[i] = INT_MAX; // set of the values of the distance array to infinity
    }
    dijkstra(0);// call the Dijkstra's algorithm function with the source node as 0

    return 0;   // return 0 to indicate successful execution of the program
}