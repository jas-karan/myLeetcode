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
        if(head==NULL) return NULL;
        
        int len=0;
        ListNode*ptr=head;
        for(int i=0;i<k && ptr;i++){
            ptr=ptr->next;
            len++;
        }
        if(len!=k) return head;
        
        ListNode*prev=NULL;
        ptr=head;
        
        while(len--){
            ListNode* nxt = ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=nxt;
        }
        
        head->next = reverseKGroup(ptr,k);
        
        return prev;
    }
};