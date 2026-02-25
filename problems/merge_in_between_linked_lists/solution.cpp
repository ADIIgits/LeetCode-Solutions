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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l2start = list2;
        ListNode* l2end = list2;
        while(l2end->next!=NULL){
            l2end = l2end->next;
        }
        ListNode* aback = NULL;
        ListNode* prev = NULL;
        ListNode* bnext = list1;
        int count=0;
        while(bnext->next!=NULL){
            if(count==a && aback==NULL) aback = bnext;
            if(count==b) break;
            if(aback==NULL) prev=bnext;
            bnext = bnext->next;
            count++;
        }
        aback = prev;
        bnext = bnext->next;

        aback->next = l2start;
        l2end->next = bnext;
        return list1;

    }
};