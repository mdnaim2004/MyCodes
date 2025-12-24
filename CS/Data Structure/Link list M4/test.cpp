// #include <bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };
// int main() {
//     Node* node = new Node(5);
//     cout << node->val << endl;

//     return 0;
// }


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

int main() {
    Node* head = new Node(5);
    Node* a = new Node(7);
    Node* b = new Node(1);
    Node* c = new Node(14);
    Node* d = new Node(3);
    Node* e = new Node(11);

    head->next = a;
    a->next = b;
    b->next = c; 
    c->next = d;
    d->next = e;

    Node* temp = head;
    int Sum = 0;

    while (temp->next != c) {
        Sum += temp->val;
        temp = temp->next;
    }

    Sum -= temp->val;

    cout << Sum << endl;   // Output: -1

    return 0;
}



// Module-4: Practice Problem


    //     Head
    //      |
    //      v
    //   +-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
    //   |  5  | 1000 | -----> |  7  | 1050 | -----> |  1  | 2000 | -----> | 14  | 1020 | -----> |  3  | 3000 | -----> | 11  | NULL |
    //   +-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
    //     500                   1000                   1050                   2000                   1020                   3000

// Why do you think linked-list requires more memory than an array when storing the same number of elements?
// Write down Three Limitations of the array which can be solved by the use of Linked List
// What is the value of Head?
// What is the value of ? marked address location?
// What will be the value of Head->Next->Next->Value?
// What will be the value of Sum following pseudocode snippets? 
// Sum = 0
// Temp = Head
// While ( Temp -> Next!= 1020){
// 	Sum += Temp-> value
// 	Temp = Temp -> Next
// }
// Sum -= Temp -> value;
