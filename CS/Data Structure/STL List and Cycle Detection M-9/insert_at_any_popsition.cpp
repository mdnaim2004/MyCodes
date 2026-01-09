// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     list<int> l ={10, 20 ,30};
//     l.insert(next(l.begin(),2), 100);

//     for(int val : l){
//         cout << val << " ";
//     }
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};
    list<int> l2 = {100,200,300,400};

    l.insert(next(l.begin(), 2), l2.begin(), l2.end());
    for(int val : l){
        cout << val << " ";
    }
    return 0;
}
