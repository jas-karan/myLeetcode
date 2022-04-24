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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next; len++;
        }
        
        if(len<k) return head;
        
        curr=head;
        ListNode*prev=NULL;
        
        for(int i=0;i<k;i++){
            ListNode*temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        
        head->next = reverseKGroup(curr,k);
        
        return prev;
        
    }
};