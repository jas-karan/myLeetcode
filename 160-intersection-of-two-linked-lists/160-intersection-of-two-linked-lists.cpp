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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>set;
        
        while(headA){
            set.insert(headA);
            headA=headA->next;
        }
        
        while(headB){
            if(set.count(headB)) return headB;
            headB=headB->next;
        }
        
        return NULL;
    }
};