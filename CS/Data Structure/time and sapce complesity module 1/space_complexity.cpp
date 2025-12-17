#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;//----------space complexity O(1)
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];  //--------------spsace complexity O(n)
    }
    return 0;
}
// only we declare in array and using loop then the complexity in O(n)...otherwise we declare normal variabe then space complexity O(1)