#include <bits/stdc++.h>
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

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = newnode;
        tail = newnode;

        return;
    }
    tail->next = newnode;
    newnode->prev = tail;

    tail = newnode;
}

void print_at_linklist(Node* &head){
    Node* temp = head;

    cout << "print Linklist : ";
    while(temp != NULL){
        cout << temp->val<<" ";

        temp = temp->next;
    }
    
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    insert_at_tail(head, tail, 100);
    insert_at_tail(head, tail, 200);
    insert_at_tail(head, tail, 500);

    print_at_linklist(head);
    return 0;
}
