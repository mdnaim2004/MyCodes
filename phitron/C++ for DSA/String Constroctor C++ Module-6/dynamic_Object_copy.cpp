#include<bits/stdc++.h>
using namespace std;

class footballer{
    public:
    string country;
    int jersey;
    footballer(string country, int jersey){
        this->country = country;
        this->jersey = jersey;
    }
};
int main(){
    footballer* messi = new footballer("Argentina", 10);
    footballer* ronaldo = new footballer("Portugal", 7);
    
    messi->country = ronaldo->country;
    messi->jersey = ronaldo->jersey;

    delete ronaldo;

    cout<<messi->country << " " << messi->jersey<<endl;
   
   return 0;
}