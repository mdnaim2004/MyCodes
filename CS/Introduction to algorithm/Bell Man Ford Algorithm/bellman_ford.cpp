#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int a,b, c;
    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main(){
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));


    }
    for(auto ed : edge_list){
        cout << ed.a << " " << ed.b << " " << ed.c << " " << endl;
    }
    return 0;
}