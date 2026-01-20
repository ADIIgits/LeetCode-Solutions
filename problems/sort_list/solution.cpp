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
        ListNode* sorted=NULL;

        if(left->val < right->val){
             sorted = left;
             left = left->next;
        }
        else {
            sorted = right;
            right = right->next;
        }

        ListNode* sorthead = sorted;

        while(left!=NULL && right!=NULL){
            
            if(left->val < right->val){
                 sorted->next = left;
                 left = left->next;
            }
            else {
                sorted->next = right;
                right = right->next;
            }

            sorted = sorted->next;

            
        }
        while(left!=NULL){
            sorted->next = left;
            left = left->next;
            sorted = sorted->next;
        }
        while(right!=NULL){
            sorted->next = right;
            right = right->next;
            sorted = sorted->next;
        }
        return sorthead;


    }
    ListNode* sot(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = getmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        right = sot(right);
        mid->next=NULL;
        left = sot(left);
        ListNode* res = merge(left,right);
        return res;
    }
public:
    ListNode* sortList(ListNode* head) {
        return sot(head);
    }
};