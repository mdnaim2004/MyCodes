#include <bits/stdc++.h>
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

void insert_at_tail(Node* &head, int val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    //im at last node in the linklist
    temp->next = newnode;
}

void print_at_tail(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val <<" ";
        temp = temp->next; 
    }
}

int main() {
    Node* head = NULL;
    //  Node* head = new Node(10);
    // Node* a = new Node(20);
    // Node* b = new Node(30);

    //head->next = a;
    //a->next = b;

    insert_at_tail(head, 40);
    insert_at_tail(head, 50);
    insert_at_tail(head, 60);
    insert_at_tail(head, 70);
    insert_at_tail(head, 80);
    insert_at_tail(head, 90);
    insert_at_tail(head, 110);

    insert_at_tail(head, 120);
    insert_at_tail(head, 130);
    insert_at_tail(head, 140);

    print_at_tail(head);
    return 0;
}
