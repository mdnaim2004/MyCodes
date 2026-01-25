/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insert_at_tail(ListNode* &head, ListNode* & tail, int val){
        ListNode* newnode = new ListNode(val);

        if( head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void reverse(ListNode* &head, ListNode* temp){
        if (temp->next == NULL) {
            head = temp;
            return;
        }
        reverse(head, temp->next);
        temp->next->next = temp;
        temp->next = NULL;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;

        ListNode* temp = head;

        while (temp != NULL) {
            insert_at_tail(newhead, newtail, temp->val);
            temp = temp->next;
        }

        reverse(newhead, newhead);

        temp = head;
        ListNode* temp2 = newhead;

        while (temp != NULL) {
            if (temp->val != temp2->val) return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;  
    }

};