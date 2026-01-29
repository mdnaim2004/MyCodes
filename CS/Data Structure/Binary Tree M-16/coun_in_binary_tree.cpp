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
    cin>>val;

    Node* root;
    if(val == -1){
        root = NULL;
    }
    else{
        root = new Node(val);
    }
    queue<Node*> q;
    if(root != NULL){
        q.push(root);
    }

    while(!q.empty()){
        Node* par = q.front();
        q.pop();

        int l,r;
        cin >> l >> r;
        Node* myleft, *myright;

        if(l == -1) myleft = NULL;
        else myleft = new Node(l);

        if(r == -1) myright =NULL;
        else myright = new Node(r);

        par->left = myleft;
        par->right = myright;

        if(par->left != NULL) q.push(par->left);
        if(par->right != NULL) q.push(par->right);
    }
    return root;

}

int count_tree(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_tree(root->left);
    int r = count_tree(root->right);

    return l+r+1;
}

int main(){
    Node* root = input_binary_tree();
    //int total = count_tree(root);
    cout << count_tree(root) << endl;
    return 0;
}