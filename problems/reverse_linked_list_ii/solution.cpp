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
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head; 
        ListNode* leftnode = NULL; 
        ListNode* rightnode = NULL; 
        int i=1; ListNode* prev = NULL; int leftfound=false;
        while(curr!=NULL){
            if(i==left){
                leftfound = true;
                leftnode = curr;
            } 
            if(i==right) {
                rightnode = curr;
                break;
            }
            i++;
            if(!leftfound) prev = curr;
            curr = curr->next;
        }
        
        ListNode* next = rightnode->next;
        rightnode->next = NULL;
        if(prev==NULL){
            //todo
            head = reverse(head);
            leftnode->next = next;
            return head;
        }
        prev->next = reverse(leftnode);
        leftnode->next = next;
        return head;
    }
};