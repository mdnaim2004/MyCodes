#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_binary_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node*> q;
    if(root)
        q.push(root);

    while(!q.empty()){
        Node* par = q.front();
        q.pop();

        int l,r;
        
    }


}

int main(){
    
    return 0;
}