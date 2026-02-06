#include<bits/stdc++.h>
using namespace std;
class myqueue{
    public:
    list<int> l;

    void push(int val){
        l.push_back(val);
    }
    void pop(){
        l.pop_back();
    }
    int front(){
        return l.front();
    }
    int back(){
        return l.back();
    }
    int size(){
        return l.size();
    }
    bool empty(){
        return l.empty();
    }
};
int main(){

    myqueue q;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int val ;
        cin >> val;
        q.push(val);
    }
    cout << "front val =  "<<  q.front() << ";"<<" back val = " << q.back()<< ";" << " queue size = "  << q.size() << " " << endl;

    while(!q.empty()){
        cout<< q.front() << endl;
        q.pop();
    }
    
    return 0;
}