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
    ListNode* reverse(ListNode*head, ListNode*prev){
        if(head==NULL) return prev;
        ListNode* hnext = head->next;
        head->next=prev;
        return reverse(hnext,head);
    }
    
    ListNode* reverseList(ListNode* head) {
        head = reverse(head,NULL);
        return head;
        
    }
};