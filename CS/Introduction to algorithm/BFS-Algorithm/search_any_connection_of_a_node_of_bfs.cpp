#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; //global variable declare
bool vis[1004]; // global variable declare......

void bfs(int src){
    queue<int> q; // 
    q.push(src);

    vis[src] = true; //all  visited value ar false to true.......step by step

    while(!q.empty()){  // we starting a loop while queue is not empty...
        int par = q.front(); // then queue er first value ke parent nam dilam
        q.pop(); //then ak ak kore value gulo ber kore anlam
        for(int child : adj_list[par]){  // akhene akta foreach loop use korlam jate amar vector er vitor je 2D array ase seitar vitor ki ki ase ta tavarse kore dekha jai....
            if(!vis[child]){ // then amra akhene check kortechi, je akhene ami kon kon value gulo tavarse korchi.....
                q.push(child); // jodi tavarse na kore thaki tahole loop er vitor dhuke ami queue er vitor amar jei value ta nilam seita push korbo
                vis[child] = true; // then ami akhene amar jei visited array ta chilo seita true kore dilam
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >>e;

    while(e--){
        int a,b;
        cin >> a>> b;
        adj_list [a].push_back(b);
        adj_list [b].push_back(a);
    }

    memset(vis, false, sizeof(vis)); // initialli ami vis ta ke false dhore nischi...

    int src, dest; // then ami 2 ta inetger variaable nilam, 

    cin >> src >> dest;

    bfs(src);  // akhene ami bfs ke call kore tar vitor source pathaia dilam......and niche check kortechi je souese ta ki destination e gase ki na....

    if(vis[dest]) cout << "YES\n";else cout << "NO\n"; // akhene ami check kortechi je amar condition ta true or false
    return 0;
}