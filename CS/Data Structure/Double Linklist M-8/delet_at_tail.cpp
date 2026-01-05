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

void delet_at_tail(Node* &head, Node* &tail){
    Node* deletNode = tail;
    tail->prev = tail;
    delete deletNode;
    
    tail->next = NULL;
}

void print_at_linklish(Node* head){
    Node* temp = head;

    cout << "Printinf Backward : ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(3);
    
    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    delet_at_tail(head, tail);

    print_at_linklish(head);

    return 0;
}
