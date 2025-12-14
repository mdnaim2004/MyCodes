#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    string nm;
    int cls;
    string s;
    int id;
    int math_marks ;
    int eng_marks ;
};

bool cmp(student a, student b)
{
    int total_a = a.math_marks + a.eng_marks;
    int total_b = b.math_marks + b.eng_marks;

    if (total_a == total_b) {
        return a.id < b.id;
    }
    return total_a > total_b;
}


int main() {
    int n;
    cin >> n;
    student arr[n];
    int total;
    for(int i=0; i<n; i++){
        cin >> arr[i].nm >> arr[i].cls >> arr[i].s >> arr[i].id >> arr[i].math_marks >> arr[i].eng_marks;  
    }
    
    sort(arr, arr + n, cmp);

    for(int i=0; i<n; i++){
        cout << arr[i].nm << " " << arr[i].cls << " " << arr[i].s << " " << arr[i].id << " " << arr[i].math_marks << " " << arr[i].eng_marks << endl;
    }

    return 0;
}
