#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int roll;
    int math;
    int phy;
    student(string name, int roll, int math, int phy){
        this->name = name;
        this->roll = roll;
        this->math = math;
        this->phy = phy;

    }
    void marks(){
        cout << "The total marks of "<< name << " = " << math+phy<<endl;
    }
};
int main(){
    student Naim("Naim", 68, 97, 95);
    Naim.marks();
    student Saima("saima", 75, 99, 99);
    Saima.marks();
    return 0;
}