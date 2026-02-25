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
    ListNode* deletenode(ListNode* head,int val){
        if(head==NULL) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            if(curr->val==val) break;
            prev=curr;
            curr = curr->next;
        }
        if(prev==NULL){
            head=head->next;
            return head;
        }
        prev->next = curr->next;
        return head;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->val==val) count++;
            curr = curr->next;
        }
        curr=head;
        for(int i=0;i<count;i++){
            head = deletenode(head,val);
        }
        return head;
    }
};