#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};
    l.erase(next(l.begin(), 2), next(l.begin(), 5));


    for(int val : l){
        cout << val << " ";
    }
    return 0;
}
