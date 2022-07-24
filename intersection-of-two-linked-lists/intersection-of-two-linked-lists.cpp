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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode*p=a,*q=b;
        
        while(p||q){
            if(p==q) return p;
            if(!p->next && !q->next) return NULL;
            p = p->next ? p->next : b;
            q = q->next ? q->next : a;
        }
        
        return NULL;
    }
};