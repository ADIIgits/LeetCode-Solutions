/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* medA = headA;
        ListNode* medB = headB;
        while(medA!=medB){
            if(medA==NULL) medA = headB;
            else medA=medA->next;
            if(medB==NULL) medB = headA;
            else medB=medB->next;
        }
        return medB;
    }
};