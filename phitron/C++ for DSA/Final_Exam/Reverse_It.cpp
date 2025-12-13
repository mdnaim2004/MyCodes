#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    string nm;
    int cls;
    string s;
    int id;
};


int main() {
    int n;
    cin >> n;

    student arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].nm >> arr[i].cls >>arr[i].s >> arr[i].id;
    }

    // reverse (s.begin(), s.end());
    
    reverse(arr, arr + n);

    for(int i=0; i<n; i++){
        cout << arr[i].nm << " " << arr[i].cls << " " << arr[i].s << " " << arr[i].id << endl;
    }

    return 0;
}


