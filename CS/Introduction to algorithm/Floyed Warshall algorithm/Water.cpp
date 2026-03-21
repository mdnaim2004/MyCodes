#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int h[n];

        for(int i=0; i<n; i++){
            cin >> h[i];
        }

        int f_max = 0, s_max = -1;

        for(int i=1; i<n; i++){
            if(h[i] > h[f_max]){
                s_max = f_max;
                f_max = i;
            }
            else if(h[i] > h[s_max]){
                s_max = i;
            }
        }
        if(f_max >= s_max)
            cout << s_max << " " << f_max << endl;
        else
            cout << f_max << " " << s_max << endl;

    }
    return 0;
}