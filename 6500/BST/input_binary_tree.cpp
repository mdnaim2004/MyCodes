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
    cin >>val;

    Node* root;

    if(val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;

    if(root) q.push(root);

    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myleft, *myright;

        if(l == -1) myleft = NULL;
        else myleft = new Node(l);

        if(r == -1) myright = NULL;
        else myright = new Node(r);

        parent->left = myleft;
        parent->right = myright;

        if(parent->left) q.push(parent->left);
        if(parent->right) q.push(parent->right);
    }
    return root;
}

bool searchBST(Node* root, int x){
    if(root == NULL) return false;

    if(root->val == x) return true;

    if(x < root->val) return searchBST(root->left, x);
    else return searchBST(root->right, x);
    
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