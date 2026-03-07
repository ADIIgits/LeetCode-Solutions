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
    int size=0;
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            size++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head==NULL) return {};
        ListNode* revhead = reverse(head);
        ListNode* curr = revhead;
        stack<int> st;

        vector<int> nextgreater(size,0);
        int k=size-1;
        while(curr!=NULL){
            int currval = curr->val;
            while(!st.empty() && st.top()<=currval){
                st.pop();
            }

            if(!st.empty()) nextgreater[k--] = st.top();
            else nextgreater[k--]=0;
            
            st.push(curr->val);

            curr=curr->next;
        }
        return nextgreater;
    }
};