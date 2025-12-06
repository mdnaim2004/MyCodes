// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    string s = "Hello World!";
//    cout << s.size()<<endl;
//    //cout<<s.max_size()<<endl;
//     s.clear();
//     cout<<s<<endl;
//    return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s1 = "Hello world";
   string s2 = "Hello World";

    // if(s1.empty() == true){
    //     cout<<"Empty"<<endl;

    // }else{
    //     cout<<"Not empty";
    // }


    // if(s1 == s2){
    //     cout<<"the string is same"<<endl;
    // }
    // else{
    //     cout<<"The string is not same......"<<endl;
    // }

    s1.resize(8);
    cout<<s1<<endl;

    s2.resize(15, '1');
    cout<<s2<<endl;
   return 0;
}