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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        int len=0;
        ListNode* med=head;
        while(med!=NULL){
            med=med->next;
            len++;
        }
        int pos = len/2;
        // if(len%2==0) pos++;

        med=head;
        int i=0;
        while(i<pos-1 && med->next!=NULL){
            med=med->next;
            i++;
        }
        med->next=med->next->next;
        return head;
    }
};