#include<bits/stdc++.h>
using namespace std;

int val[10005];
int weight[10005];
int max_weight;

int knapsack(int i, int max_weight){
    //two options.....
    //1.bag e rakhbo....
    //2.bag e rakhbo nah....

    int opt1 = knapsack(i-1, max_weight - max_weight[i]);
    int opt2 = knapsack(i-1, max_weight);

    return max(opt1, opt2);
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

    knapsack(n-1,max_weight);

    return 0;
}