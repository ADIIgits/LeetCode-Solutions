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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans=NULL;
        ListNode* ansptr=NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = carry + l1->val + l2->val;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else carry = 0;
            if(ans==NULL) {
                ans = new ListNode(sum,NULL);
                ansptr = ans;
            }
            else{
                ansptr->next = new ListNode(sum,NULL);
                ansptr = ansptr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = carry + l1->val;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else carry = 0;

            ansptr->next = new ListNode(sum,NULL);
            ansptr = ansptr->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = carry + l2->val;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else carry = 0;

            ansptr->next = new ListNode(sum,NULL);
            ansptr = ansptr->next;
            l2 = l2->next;
        }
        if(carry>0) ansptr->next = new ListNode(carry,NULL);
        ans = reverse(ans);
        return ans;
    }
};