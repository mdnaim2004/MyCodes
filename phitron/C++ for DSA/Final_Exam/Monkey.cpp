#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100005];

    while (cin.getline(s, 100005)) {
        int length = strlen(s);
        int k = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == ' '){
                continue; 
            } 
            s[k++] = s[i];
        }
        s[k] = '\0';
        sort(s, s + k);
        cout << s << endl;
    }

    return 0;
}
