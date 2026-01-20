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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l1med = l1;
        ListNode* l2med = l2;
        ListNode* header = NULL;
        ListNode* ans = NULL;
        while(l1med!=NULL || l2med!=NULL || carry!=0){

            int sum = carry;

            if(l1med){
                sum += l1med->val;
                l1med = l1med->next;
            }
            if(l2med){
                sum += l2med->val;
                l2med = l2med->next;
            }
            if(sum>=10){ 
                carry = sum/10;
                sum = sum%10; 
            } else carry = 0;
            
            if(ans==NULL) {
                ans = new ListNode(sum,NULL); 
                header = ans;
            }
            else {
                ans->next = new ListNode(sum,NULL); 
                ans = ans->next;
            }            
        }
        return header;
        
    }
};