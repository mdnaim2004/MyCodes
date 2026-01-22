#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string val;
    Node* next;
    Node* prev;

    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string s){
    Node* newnode = new Node(s);

    if(head == NULL){
        head = newnode;
        tail = newnode;

        return;
    }
    tail->next = newnode;
    newnode->prev = tail;

    tail = newnode;

}

Node* find_at_node(Node* &head, string s){
    Node* temp = head;

    while(temp != NULL){

        if(temp->val == s){

            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void visit_next_node(Node* &current){

    if(current->next == NULL){
        cout << "Not Available" << endl;
    }
    else{
        current = current->next;

        cout << current->val << endl;
    }
}

void visit_prev_node(Node* &current){

    if(current->prev == NULL){
        cout<< "Not Available" << endl;
    }
    else{
        current = current->prev;

        cout<<current->val << endl;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    string s;
    
    while(cin >> s){
        if(s =="end"){
            break;
        }

        insert_at_tail(head, tail, s);
    }

    int q;
    cin >> q;

    Node* current = head;


    while(q--){
        string input;
        cin >> input;

        if(input == "visit"){
            string s;
            cin >> s;

            Node* target = find_at_node(head, s);

            if(target == NULL){
                cout << "Not Available" << endl;

            }
            else{
                current = target;

                cout<< current->val << endl;
            }
        }
        else if(input == "next"){
            visit_next_node(current);
        }
        else if(input =="prev"){
            visit_prev_node(current);
        }
    }
}
