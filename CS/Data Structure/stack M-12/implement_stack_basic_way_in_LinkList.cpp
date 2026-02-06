#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class mystack{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    int sz = 0;
    
    void push(int val){
        Node* newnode = new Node(val);
        sz++;

        if(tail == NULL){
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop(){
        if(tail == NULL) return;   // empty check
        sz--;

        Node* deletenode = tail;
        tail = tail->prev;

        if(tail != NULL) tail->next = NULL;
        else head = NULL;

        delete deletenode;
    }

    int top(){
        if(tail == NULL) return -1;
        return tail->val;
    }


    int size(){
        return sz;
    }

    bool empty(){
        return head == NULL;
    }

};

int main(){
    
    mystack st;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty()){
        cout <<"the stack is : "<<st.top() << endl;
        st.pop();
    }

    return 0;
}