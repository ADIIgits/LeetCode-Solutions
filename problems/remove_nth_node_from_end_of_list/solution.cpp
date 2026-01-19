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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return head=NULL;
        int len=0;
        ListNode* med=head;
        while(med!=NULL){
            med=med->next;
            len++;
        }
        int pos = len-n;
        cout<<pos<<" ";
        int i=0;
        med=head;
        while(i<pos-1 && med->next->next!=NULL){
            med=med->next;
            i++;
        }
        if(pos<=0) return head->next;
        med->next = med->next->next;
        return head;
    }
};