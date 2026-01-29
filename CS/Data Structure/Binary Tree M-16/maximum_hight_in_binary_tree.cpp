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
Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty()){
        Node* pr = q.front();
        q.pop();
        int l,r;
        cin >> l >> r;
        Node* myleft, *myright;
        if(l == -1) myleft = NULL;
        else myleft = new Node(l);
        
        if(r == -1) myright = NULL;
        else myright = new Node(r);

        pr->left = myleft;
        pr->right = myright;

        if(pr->left) q.push(pr->left);
        if(pr->right) q.push(pr->right);
    }
    return root;
}

int max_height(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l,r)+1;
}

int main(){
    Node* root = input_tree();
    cout<<max_height(root)<<endl;
    
    return 0;
}