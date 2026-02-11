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
        cin >> l >> r;

        Node* myleft, *myright;
        if(l == -1) myleft = NULL;
        else myleft = new Node(l);

        if(r == -1) myright = NULL;
        else myright = new Node(r);

        par->left = myleft;
        par->right = myright;

        if(par->left) q.push(par->left);
        if(par->right) q.push(par->right);

    }
    return root;


}

bool searchBST(Node* root, int val){
    if(root == NULL)
        return false;
    
    if(root->val == val)
        return true;

    if(root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main(){
    Node* root = input_binary_tree();
    int val;
    cin >> val;

    if(searchBST(root,val))
        cout << "Found" << endl;
    else
        cout << "Not Found" <<endl;
        
    return 0;
}