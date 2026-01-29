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
    // ListNode* lastlink = NULL;
    // ListNode* prevklink =   NULL;
    // ListNode* globalhead = NULL;
    ListNode* reverse(ListNode* head){
        if(head==NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseknodes(ListNode* head, int k){
        if(head==NULL) return NULL; //or head->next==null as well?
        ListNode* temp = head;
        int count=1;
        while(count<k){
            if(temp->next==NULL) return head;
            temp = temp->next; 
            count++;
        }
        
        
        ListNode* nextgroupStart = NULL;
        nextgroupStart = temp->next;
        temp->next=NULL; 
        ListNode* reversed = reverse(head);
        head->next=reverseknodes(nextgroupStart,k);
        return reversed;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        return reverseknodes(head,k);
    }
};