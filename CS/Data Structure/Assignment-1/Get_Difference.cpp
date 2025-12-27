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

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

// void print_link_list(Node* &head){
//     Node* temp = head;

//     while(temp != NULL){
//         cout << temp->val << " ";
//         temp = temp->next;
//     }

// }


int difference_min_max(Node* head){

    if (head == NULL){
        return 0;
    }

    int max = head->val;
    int min = head->val;

    Node* temp = head->next;

    while (temp != NULL) {
        if (temp->val > max) {
            max = temp->val;
        }

        if (temp->val < min) {
            min = temp->val;
        }
        temp = temp->next;

    }

    int diff = max - min;

    cout << diff <<endl;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    while(1){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    difference_min_max(head);
    
    return 0;
}
