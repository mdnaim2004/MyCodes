#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    vector<pair<int, int>> v;

    for(int i=1; i<=v.size(); i++){
        v.push_back({arr[i], i+1});
    }
    sort(v.begin(), v.end());

    int i=1;

    while(i < v.size()){
        int val = v[i].first;
        int fst = v[i].second;
        int lst = v[i].second;
        
        int j = i;

        while(j < v.size() && v[i].first == val){
            lst = v[j].second;
            j++;
        }

        cout << val << " " << fst << " " << lst << endl;
        i = j;

    }
    return 0;
}