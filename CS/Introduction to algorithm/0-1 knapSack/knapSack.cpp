#include<bits/stdc++.h>
using namespace std;

int val[10005];
int weight[10005];
int max_weight;

int knapsack(int i, int max_weight){
    if(i<0 || max_weight <=0){
        return 0;
    }

    if(weight[i] <= max_weight){
        //two options.....
        //1.bag e rakhbo....
        //2.bag e rakhbo nah....
        int opt1 = knapsack(i-1, max_weight - weight[i]) + val[i];
        int opt2 = knapsack(i-1, max_weight);

        return max(opt1, opt2);
    }
    else{
        //1 option....
        //1. bag e rakhte parbo nah....
        return knapsack(i-1, max_weight);
        
    }


}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;

    cout << knapsack(n-1,max_weight) << endl;

    return 0;
}