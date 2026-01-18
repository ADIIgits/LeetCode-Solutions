/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int f=0;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                f=1;
                break;
            }
        }
        if(f==0) return NULL;
        slow = head;
        while(fast!=NULL && slow!=NULL){
            if(slow==fast) return slow;
            slow=slow->next;
            fast=fast->next;
        }
        return fast;

    }
};