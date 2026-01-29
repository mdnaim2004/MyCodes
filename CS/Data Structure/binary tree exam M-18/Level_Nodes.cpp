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

void print_level(Node* root, int x, int level, int &flag){
    if(root == NULL) return;
    if(level == x){
        cout << root->val << " ";
        flag = 100;
        return;
    }
    print_level(root->left, x, level+1, flag);
    print_level(root->right, x, level+1, flag);
}


int main(){
    Node* root = input_tree();
    int x;
    cin >> x;

    int flag = 200;
    print_level(root,x,0,flag);
    
    if(flag == 200){
        cout << "Invalid" << endl;
    }

    return 0;
}