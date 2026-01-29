// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//         int val;
//         Node* left;
//         Node* right;

//     Node(int val){
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Node* input_tree(){
//     int val;
//     cin >> val;
//     Node* root;
//     if(val == -1) root = NULL;
//     else root = new Node(val);

//     queue<Node*> q;
//     if(root) q.push(root);

//     while(!q.empty()){
//         Node* pr = q.front();
//         q.pop();
//         int l,r;
//         cin >> l >> r;
//         Node* myleft, *myright;
//         if(l == -1) myleft = NULL;
//         else myleft = new Node(l);
        
//         if(r == -1) myright = NULL;
//         else myright = new Node(r);

//         pr->left = myleft;
//         pr->right = myright;

//         if(pr->left) q.push(pr->left);
//         if(pr->right) q.push(pr->right);
//     }
//     return root;
// }

// int total_Node(Node* root){
//     if(root == NULL){
//         return 0;
//     }
//     if(root->left == NULL && root->right == NULL){
//         return 1;
//     }
//     int l = total_Node(root->left);
//     int r = total_Node(root->right);

//     return l+r+1;
// }
// int max_hight(Node* root){
//     if(root == NULL) return 0;
//     if(root->left == NULL && root->right == NULL) return 1;

//     int l = max_hight(root->left);
//     int r = max_hight(root->right);

//     return max(l,r)+1;
// }

// int main(){
//     Node* root = input_tree();
//     // cout << total_Node(root) << endl;
//     // cout  << max_hight(root) << endl;

//     if(total_Node(root) == max_hight(pow)2,max_hight, -1){
//         cout << 
//     }
    
//     return 0;
// }

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
int perfect_binary_tree(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int l = perfect_binary_tree(root->left);
    int r = perfect_binary_tree(root->right);

    return ;
}
int main(){
    Node* root = input_tree();
    cout << perfect_binary_tree(root) << endl;
    
    return 0;
}