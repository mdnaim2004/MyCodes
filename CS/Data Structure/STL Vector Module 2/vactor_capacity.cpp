#include <bits/stdc++.h>
using namespace std;

int main() {
    //vector <int> v;
    //cout << v.capacity() << endl;

    vector<int>v;
    cout<<v.capacity() <<endl;
    v.push_back(19);
    cout << v.capacity() <<endl;
    v.push_back(20);
    cout<<v.capacity()<<endl;
    v.push_back(30);
    cout << v.capacity() << endl;
    v.push_back(30);
    cout << v.capacity() << endl;
    v.push_back(30);
    cout << v.capacity() << endl;

    cout<< "Vector size :";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;
    cout << "Vector resize :";
    v.resize(4);
    for(int i=0; i<v.size(); i++){
        cout << v[i]<< " ";
    }
    cout << endl;
    cout <<"increase the vector and set value of vector:";

    v.resize(10,200);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }

    return 0;
}
//vector time complexity O(1).........