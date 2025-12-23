#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
};

int main() {
    Node a,b,c,d;
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    cout << a.val << " " << b.val << " "  << c.val << " " << d.val << " ";
    return 0;
}
