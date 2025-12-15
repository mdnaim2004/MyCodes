#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int roll;
    int marks;
};

int main() {
    int n;
    cin >> n;
    student arr[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        cin >> arr[i].name >> arr[i].roll >> arr[i].marks;
    }
    //cout<<"The final output is :"<<endl;
    for(int i=0; i<n; i++){
        cout << arr[i].name <<" " << arr[i].roll <<" " << arr[i].marks << endl;
    }
    return 0;
}


