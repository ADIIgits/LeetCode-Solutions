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
    ListNode* getmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getmid(head);
        ListNode* front = head;
        ListNode* second = reverse(mid->next);
        mid->next = NULL; //separate the lists
        while(second!=NULL){
            if(front->val!=second->val) return false;
            front=front->next;
            second=second->next;
        }
        return true;


    }
};