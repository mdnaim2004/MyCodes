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

void delete_at_any_position(Node* &head, int indx){
    Node* temp = head;

    for(int i = 0; i < indx - 1; i++){
        temp = temp->next;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;
    deleteNode->next->prev = temp;

    delete deleteNode;
}


void print_at_linklish(Node* &head){
    Node* temp = head;

    cout << "Printinf linklist : ";
    while(temp != NULL){
        cout << temp->val << " ";
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

    delet_at_any_position(head, 1);

    print_at_linklish(head);

    return 0;
}
