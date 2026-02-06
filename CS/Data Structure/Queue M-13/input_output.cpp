#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
        
    }
};
class myqueue{
    public:

    Node* head = NULL;
    Node* tail = NULL;

    int siz = 0;

    void push(int val){

        siz++;

        Node* newnode = new Node(val);

        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    }

    void pop(){

        siz--;

        Node* deletnode = head;

        head = head->next;
        delete deletnode;
        
        if(head == NULL){
            tail = NULL;
        }
    }

    int front(){
        return head->val;
    }

    int back(){
        return tail->val;
    }

    int size(){
        return siz;
    }

    bool empty(){
        return head == NULL;
    }
};
int main(){

    myqueue q;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int val ;
        cin >> val;
        q.push(val);
    }
    cout << "front val =  "<<  q.front() << ";"<<" back val = " << q.back()<< ";" << " queue size = "  << q.size() << " " << endl;

    while(!q.empty()){
        cout<< q.front() << endl;
        q.pop();
    }
    
    return 0;
}