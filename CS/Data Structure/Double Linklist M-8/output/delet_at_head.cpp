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

void delet_at_head(Node* &head, Node* &tail){
    Node* deletnode = head;
    head = head->next;
    delete deletnode;

    if(head == NULL){
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void print_link_list(Node* &head){
    Node* temp = head;

    cout << "the linklist is : ";
    while(temp != NULL){
        cout << temp->val <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(10);
    Node* tail = new Node(30);
    
    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;


    delet_at_head(head, tail);

    print_link_list(head);

    return 0;
}
