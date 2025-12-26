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

void insert_at_any_position(Node* &head, int indx, int val){
    Node* newnode = new Node(val);

    if(head ==NULL){
        head = newnode;
        return;
    }

    Node* temp = head;

    for(int i=0; i<indx - 1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

void print_at_new_position(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val <<" ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    // Node* head = new Node(10);
    // Node* a = new Node(20);
    // Node* b = new Node(30);

    // head->next = a;
    // a->next = b;

    insert_at_any_position(head, 1, 200);

    print_at_new_position(head);

    return 0;
}
