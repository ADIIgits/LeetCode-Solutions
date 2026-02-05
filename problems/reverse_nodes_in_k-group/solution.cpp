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
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* kthstart = head;
        ListNode* kthlast = head;
        int i=1;
        while(kthlast->next!=NULL && i<k){
            kthlast=kthlast->next;
            i++;
        }
        if(i<k) return head;

        ListNode* nextkhead = kthlast->next;
        kthlast->next = NULL;
        ListNode* revhead = reverse(kthstart);
        kthstart->next = reverseKGroup(nextkhead,k);
        return revhead;
    }
};