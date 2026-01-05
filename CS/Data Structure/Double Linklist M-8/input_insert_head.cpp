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

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);

    if(head ==NULL){
        head = newnode;
        tail = newnode;

        return;
    }

    newnode->next = head;
    head->prev = newnode;

    head = newnode;

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

void print_at_Backward_linklish(Node* &tail){
    Node* temp = tail;

    cout << "Printinf Backward : ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(1){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_head(head, tail, val);
    }


    print_at_linklish(head);

    print_at_Backward_linklish(tail);
    

    return 0;
}
