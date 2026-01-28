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

void insert_linklist(Node* &head, Node* &tail, int &size, int x, int val){

    Node* newnode = new Node(val);

    if(size == 0){
        head = newnode;
        tail = newnode;
    }

    else if(x == 0){
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else if(x == size){
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    
    else{
        Node* current = head;

        for(int i=0; i<x; i++){
            current = current->next;
        }

        Node* prev_node = current->prev;

        prev_node->next = newnode;
        newnode->prev = prev_node;

        newnode->next = current;
        current->prev = newnode;
    }

    size++;
}

void print_at_left_linklish(Node* head){
    Node* temp = head;

    cout << "L -> ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_at_rigth_linklish(Node* &tail){
    Node* temp = tail;

    cout << "R -> ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main(){
    int q;
    cin >> q;

    Node* head = NULL;
    Node* tail = NULL;

    int size = 0;

    while(q--){
        int x,val;

        cin >> x >> val;

        if(x < 0 || x > size){
            cout << "Invalid" << endl;
        }
        else{
            insert_linklist(head, tail, size, x, val);
            print_at_left_linklish(head);
            print_at_rigth_linklish(tail);
        }
    }

}