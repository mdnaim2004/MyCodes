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

void inssert_at_head(Node* &head, int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void print_link_list(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;
    
    inssert_at_head(head, 100);
    inssert_at_head(head, 200);
    inssert_at_head(head, 300);
    inssert_at_head(head, 400);
    inssert_at_head(head, 500);

    print_link_list(head);
    return 0;
}
