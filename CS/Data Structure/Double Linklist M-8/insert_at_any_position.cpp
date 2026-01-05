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

void insert_at_any_position(Node* &head, Node* &tail, int indx, int val){
    Node* newnode = new Node(val);

    Node* temp = head;

    for(int i=0; i<indx; i++){
        temp = temp->next;
    }
    //cout << temp->val;


    //conection between newnode and next indx
    newnode->next = temp->next;
    temp->next->prev = newnode;

    //connection between newnode and before indx
    temp->next = newnode;
    newnode->prev = temp;

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


    //add index and value
    insert_at_any_position(head, tail, 1, 200);
    insert_at_any_position(head, tail, 2, 300);
    insert_at_any_position(head, tail, 3, 400);
    insert_at_any_position(head, tail, 4, 500);


    //printing the
    print_at_linklist(head);

    return 0;
}
