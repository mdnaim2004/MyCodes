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
    void reverse(ListNode* &head, ListNode* temp){
        if(temp->next == NULL){
            head = temp;
            return ;
        }
        reverse(head, temp->next);
        temp->next->next = temp;
        temp->next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        reverse(head, head);
        return head;
    }
};