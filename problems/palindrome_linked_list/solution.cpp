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
    ListNode* reverse(ListNode* list){
        ListNode* prevnode = NULL;
        ListNode* currnode = list;
        ListNode* nextnode = NULL;
        while(currnode!=NULL){
            nextnode = currnode->next;
            currnode->next = prevnode;

            prevnode = currnode;
            currnode = nextnode;    
        }
        return prevnode;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* orgcurr = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = reverse(slow->next);
        ListNode* revhead = rev;
        while(revhead!=NULL){
            if(orgcurr->val!=revhead->val) return false;
            orgcurr=orgcurr->next;
            revhead = revhead->next;
        }
        return true;
    }
};
