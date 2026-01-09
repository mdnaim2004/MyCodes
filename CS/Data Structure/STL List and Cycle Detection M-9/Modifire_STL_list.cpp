#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};

    list<int> l2;
    l2 =l;

    l2.push_back(100);
    l2.push_front(500);

    

    for(int val : l2){
        cout << val << " ";
    }
    return 0;
}
