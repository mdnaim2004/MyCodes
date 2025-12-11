#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--){
        string s, x;
        cin >> s >> x;

        int fst = s.size();
        int sec = x.size();
        for(int i = 0; i<=fst-sec; i++){
            int flag = 100;

            for(int j=0; j<sec; j++){
                if(s[i+j] != x[j]){
                    flag = 200;
                    return;
                }
            }
            if(flag == 100){
                s.replace(i, sec, "#");
                fst = s.size();  
            }
        }
        cout << s<< endl;
    }
    return 0;
}
