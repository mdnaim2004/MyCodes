#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Student{
public:
    int roll;
    char name[101];
    char section;
    int marks;

    Student(int roll, const char name[], char section, int marks){
        strcpy(this->name, name);
        this->roll = roll;
        this->section = section;
        this->marks = marks;
    }
};
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int roll;
        char name[101];
        char section;
        int marks;

        cin >> roll >> name >> section >> marks;
        Student s1(roll, name, section, marks);

        cin >> roll >> name >> section >> marks;
        Student s2(roll, name, section, marks);

        cin >> roll >> name >> section >> marks;
        Student s3(roll, name, section, marks);

        Student hight = s1;

        if(s1.marks > hight.marks || (s1.marks == hight.marks && s1.roll < hight.roll)){
            hight = s1;
        }
        if (s2.marks > hight.marks || (s2.marks == hight.marks && s2.roll < hight.roll)) {
            hight = s2;
        }
       if(s3.marks > hight.marks || (s3.marks == hight.marks && s3.roll < hight.roll)) {
            hight = s3;
        }
        cout << hight.roll << " " << hight.name << " " << hight.section << " " << hight.marks;
        cout << endl;
    }

    return 0;
}
