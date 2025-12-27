
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<long long int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<long long int> prefix_sum(n);

    prefix_sum[0] = arr[0];

    for(int i=1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    reverse(prefix_sum.begin(), prefix_sum.end());

    for(int i = 0; i < n; i++){
        cout << prefix_sum[i] << " ";
    }


    return 0;
}
