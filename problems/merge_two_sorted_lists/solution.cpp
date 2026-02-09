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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = NULL;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;

        if(l1->val < l2->val){
            merged = l1;
            l1 = l1->next;
        } else {
            merged = l2;
            l2 = l2->next;
        }
        ListNode* mergedhead = merged;
        while(l1!=NULL && l2!=NULL){
            int val1 = l1->val; int val2 = l2->val;
            if(val1<val2){
                merged->next = new ListNode(val1,NULL);
                merged = merged->next;
                l1 = l1->next;
            } else {
                merged->next = new ListNode(val2,NULL);
                merged = merged->next;
                l2 = l2->next;
            }
        }
        while(l1!=NULL){
            int val1 = l1->val;
            merged->next = new ListNode(val1,NULL);
            merged = merged->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int val2 = l2->val;
            merged->next = new ListNode(val2,NULL);
            merged = merged->next;
            l2 = l2->next;
        }
        return mergedhead;
    }
    
};