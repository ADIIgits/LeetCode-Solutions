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
    ListNode* getmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* sorted = NULL;
        if(left->val < right->val){
            sorted = left;
            left = left->next;
        }
        else {
            sorted = right;
            right = right->next;
        }

        ListNode* sortedhead = sorted;
        while(left!=NULL && right!=NULL){
            int leftval = left->val;
            int rightval = right->val;
            if(leftval < rightval){
                sorted->next = new ListNode(leftval,NULL);
                sorted=sorted->next;
                left=left->next;
            } else {
                sorted->next = new ListNode(rightval,NULL);
                sorted=sorted->next;
                right=right->next;
            }
        }
        while(left!=NULL){
            int leftval = left->val;
            sorted->next = new ListNode(leftval,NULL);
            sorted=sorted->next;
            left=left->next;
        }
        while(right!=NULL){
            int rightval = right->val;
            sorted->next = new ListNode(rightval,NULL);
            sorted=sorted->next;
            right=right->next;
        }
        return sortedhead;

    }
    ListNode* sot(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = getmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        right = sot(right);
        mid->next=NULL;
        left = sot(left);
        ListNode* merged = merge(left,right);
        return merged;
    }
public:
    ListNode* sortList(ListNode* head) {
        return sot(head);
    }
};