#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int a,b,c;

    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
long long int dis[1005];
vector<Edge> edge_list;
int n,e;
bool cycle = false;

void bellman_ford(){
    for(int i=1; i<=n; i++){
        for(auto ed : edge_list){
            int a,b,c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for(auto ed : edge_list){
        int a,b,c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if(dis[a] != LLONG_MAX && dis[a]+c < dis[b]){
            cycle = true;
            break;
        }
    }
}

int main(){
    //int n,e;
    cin >> n >> e;
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a,b,c));

    }

    int src;
    cin >>src;

    int t;
    cin >> t;

    for(int i=1; i<=n; i++){
        dis[i] = LLONG_MAX;
    }
    dis[src] = 0;
    bellman_ford();

    while(t--){
        int d;
        cin >>d;

        if(cycle){
            cout<<"Negative Cycle Detected"<< endl;
            break;
        }
        else{
            if(dis[d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }

        
    }

    
    return 0;
}