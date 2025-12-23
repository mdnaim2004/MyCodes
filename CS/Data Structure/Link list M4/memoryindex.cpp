#include <bits/stdc++.h>
using namespace std;

int main() {
    //int n = 5;
    //cin >> n;
    //int arr[5] = {1, 2, 3, 4, 5};
    vector<int>arr = {1,2,3,4,5};

    arr.push_back(100);

    cout << &arr[4] << "  " << &arr[5];
    return 0;
}
