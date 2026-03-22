#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> high(n);

        for(int i=0; i<n; i++){
            cin >> high[i];
        }

        int fst_max = 0, sec_max = -1;

        for(int i=1; i<n; i++){
            if(high[i] > high[fst_max]){
                sec_max = fst_max;
                fst_max = i;
            }
            else if(sec_max == -1 || high[i] > high[sec_max]){
                sec_max = i;
            }
        }
        if(fst_max >= sec_max)
            cout << sec_max << " " << fst_max << endl;
        else
            cout << fst_max << " " << sec_max << endl;

    }
    return 0;
}