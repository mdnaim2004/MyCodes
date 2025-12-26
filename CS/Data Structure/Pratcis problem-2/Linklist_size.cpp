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

void count_linklist(Node* head){
    int count = 0;
    Node* temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    cout << count;
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

    //rint_link_list(head);
    count_linklist(head);
    return 0;
}
