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
    void deleteNode(ListNode* node) {

        ListNode* currnode=node;
        ListNode* prev=NULL;
        while(currnode->next!=NULL){
            ListNode* nextnode = currnode->next;
            int val = nextnode->val;
            currnode->val = val;
            prev = currnode;
            currnode=currnode->next;
        }
        prev->next = NULL;
    }
};