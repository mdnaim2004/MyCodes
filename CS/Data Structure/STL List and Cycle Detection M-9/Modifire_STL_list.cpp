#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};

    list<int> l2;
    l2 =l;


    // pichone value add kora
    l2.push_back(100);

    // samne value add kora
    l2.push_front(500);

    //pichone theke value bad deoa
    l2.pop_back();

    //samne theke value bad deoa
    l2.pop_front();

    l2.pop_back();
    l2.pop_front();

    for(int val : l2){
        cout << val << " ";
    }
    return 0;
}
