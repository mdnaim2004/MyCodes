#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int roll;
    int marks;

};
bool cmp(student i, student j){
    if(i.marks < j.marks){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    int n;
    cin >> n;
    student arr[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        cin >> arr[i].name >> arr[i].roll >> arr[i].marks;
    }
    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++){
        cout << arr[i].name << " " << arr[i].roll << "  " <<arr[i].marks<<endl;
    }
    return 0;
}
