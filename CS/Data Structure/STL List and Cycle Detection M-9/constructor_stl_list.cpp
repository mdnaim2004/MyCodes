#include <bits/stdc++.h>
using namespace std;

int main() {
    
    //     list<int> mylist   timecomplexiy = O(1)

    // same as a vector

    // list<int> mylist;
    // cout<<mylist.size() << endl;


    // list<int> l(10);
    // cout << *(l.begin()) << endl;

    
    // cout << *(l.begin()) << endl;

    list<int> l(10, 3);

    // for(auto it = l.begin(); it != l.end(); it++){
    //     cout << *it << endl;
    // }

    for(int val:l){
        cout << val << " ";
    }

    return 0;
}
