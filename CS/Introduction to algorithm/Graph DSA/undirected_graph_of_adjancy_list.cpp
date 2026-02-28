#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];
    while(e--){
        int a, b;
        cin >>a >> b;

        adj_list [a].push_back(b);

        //adj_list [b].push_back(a);  //for undirected graph........

    }

    for(int i=0; i<n; i++){
        cout << i << " ==> ";

        for(int x : adj_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}










CREATE table shiping(
	shiping_id int,
	status char(20),
	coustomers int,
	FOREIGN key (coustomers) REFERENCES coustomers (coustomer_id)
);

INSERT into shiping VALUES (1, pending, 2);
INSERT into shiping VALUES (2, pending, 4);
INSERT into shiping VALUES (3, delevery, 3);
INSERT into shiping VALUES (4, pending, 5);
INSERT into shiping VALUES (5, delevary, 1);

SELECT *FROM shiping;
