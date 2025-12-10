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
    cin>>n;
    student arr[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        cin>>arr[i].name >> arr[i].roll >>arr[i].marks;
    }
    //int minimum = INT_MAX;

    student minimum;
    minimum.marks = INT_MAX;

    for(int i=0; i<n; i++){
        //cout<<arr[i].name << " " <<arr[i].roll <<" " << arr[i].marks <<endl;
        //minimum = min(arr[i].marks, minimum);
        if(arr[i].marks < minimum.marks){
            minimum = arr[i];
        }
    }
    cout << minimum.name << " "<<minimum.roll <<" " << minimum.marks << endl;
    return 0;
}
