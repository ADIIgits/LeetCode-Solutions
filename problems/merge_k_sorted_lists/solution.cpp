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
    ListNode* mergelist(ListNode* a,ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* merged = NULL;
        ListNode* mergedhead = NULL;
        ListNode* aptr = a;  ListNode* bptr = b;
        if(a->val < b->val){
            merged = a;
            aptr = aptr->next;
        } else {
            merged = b;
            bptr = bptr->next;
        }
        mergedhead = merged;
        while(aptr!=NULL && bptr!=NULL){
            if(aptr->val < bptr->val){
                merged->next = aptr;
                merged = merged->next;
                aptr = aptr->next; 
            } else {
                merged->next = bptr;
                merged = merged->next;
                bptr = bptr->next; 
            }
        }
        while(aptr!=NULL){
            merged->next = aptr;
            merged = merged->next;
            aptr = aptr->next;
        }
        while(bptr!=NULL){
            merged->next = bptr;
            merged = merged->next;
            bptr = bptr->next; 
        }
        return mergedhead;

    }
    ListNode* divide(vector<ListNode*>& lists,int l,int r){
        if(l==r) return lists[l];
        int mid = (l + r)/2;
        ListNode* left = divide(lists,l,mid);
        ListNode* right = divide(lists,mid+1,r);
        return mergelist(left,right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int n = lists.size();
        return divide(lists,0,n-1);
    }
};