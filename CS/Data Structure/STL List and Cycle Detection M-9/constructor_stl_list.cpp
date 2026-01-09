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

    // list<int> l(10, 3);

    // for(auto it = l.begin(); it != l.end(); it++){
    //     cout << *it << endl;
    // }

    list<int> l = {1,2,3,4,5,6,7,8,9};
    list<int> l2(l);

    for(int val: l2){
        cout << val << " ";
    }

    return 0;
}
