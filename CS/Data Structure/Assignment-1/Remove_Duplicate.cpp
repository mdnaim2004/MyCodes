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



void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void duplicate_remove(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        Node* current = temp;

        while(current->next != NULL){
            if(current->next->val == temp->val){
                Node* del = current->next;
                current->next = del->next;
                
                delete del;
            }
            else{
                current = current->next;
            }
        
        }
        temp = temp->next;
    }
}


void print_link_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }

        insert_at_tail(head, tail, val);
    }

    duplicate_remove(head);
    print_link_list(head);

    
    return 0;
}