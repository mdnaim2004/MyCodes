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

void insert_at_head(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

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

void delet_at_indx(Node* &head, Node* &tail, int indx)
{
    if(head == NULL){
        return;
    }
    if(indx == 0){
        Node* temp = head;
        head = head->next;
        delete temp;

        if(head == NULL){
            tail = NULL;

        }
        return;
    }

    Node* temp = head;
    for(int i = 1; i < indx; i++){
        if(temp->next == NULL){
            return;
        }
        temp = temp->next;

    }
    if(temp->next == NULL){
        return;
    }

    Node* deletnode = temp->next;
    temp->next = deletnode->next;
    if(deletnode == tail){
        tail = temp;
    }
    delete deletnode;

}



void print_link_list(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    int q;
    cin >> q;
    while(q--){
        int x, v;
        cin >> x >> v;

        if(x == 0){
            insert_at_head(head, tail, v);
        }
        else if(x == 1){
            insert_at_tail(head, tail, v);
        }
        else if(x == 2){
            delet_at_indx(head, tail, v);
        }

        print_link_list(head);
    }

    
    
    return 0;
}