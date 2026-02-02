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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL) return head;
        ListNode* med = head; int size=0;
        while(med!=NULL) {med=med->next; size++;}
        k=k%size;
        for(int i=0;i<k;i++){
            ListNode* temp = head;
            while(temp->next->next!=NULL) temp = temp->next;
            ListNode* firstnode = temp->next;
            temp->next = NULL;
            firstnode->next = head;
            head=firstnode;
            // temp = temp->next;
        }
        return head;
    }
};