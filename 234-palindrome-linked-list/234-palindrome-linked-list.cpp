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
    ListNode* rev(ListNode* head){
	    ListNode*prev = NULL;
	    ListNode*curr = head;
	
	    while(curr){
	    	ListNode*t=curr->next;
		    curr->next=prev;
		    prev=curr;
		    curr = t;
	    }
	
	    return prev;
    }

    
    bool isPalindrome(ListNode* list) {
        if(!list || !list->next) return true;
	
	    ListNode*slow=list,*fast=list;
	
	    while(fast->next && fast->next->next){
	    	slow=slow->next; fast=fast->next->next;
	    }
	    ListNode*plist = rev(slow->next);
	    slow->next = NULL;
	
	    while(plist){
		    if(list->val!=plist->val) return false;
		    list=list->next;
		    plist=plist->next;
	    }
	
	    return true;
    }
};