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

void print_link_list(Node* &head){
    Node* temp = head;
    cout <<"LINK LIST :";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

}
// void delet_likn_list(Node* &head){
//     Node* deletnode = head;
//     head = head->next;
//     delete deletnode;
// }

void delet_at_tail(Node* &head,Node* &tail, int indx){
    Node* temp = head;
    for(int i=1; i<indx; i++){
        temp = temp->next;
    }
    Node* deletnode = temp->next;
    temp->next = temp->next->next;
    delete deletnode;
    tail = temp;
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
    cout << "before delet tail : " << tail->val <<endl;
    // delet_likn_list(head);
    // delet_likn_list(head);
    // delet_likn_list(head);
    // delet_likn_list(head);
    delet_at_tail(head, tail, 4);

    print_link_list(head);
    
    cout <<endl << "after delet tail : " << tail->val <<endl;

 
    
    return 0;
}
