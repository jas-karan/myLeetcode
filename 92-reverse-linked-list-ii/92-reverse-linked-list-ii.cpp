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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
	
	    ListNode*dummy = new ListNode(0);
	    dummy->next = head;
	
	    ListNode*curr = dummy;
	    ListNode*prev = NULL;
	
	    for(int i=0;i<left;i++){
		    prev=curr;
		    curr=curr->next;
	    }
	
	    ListNode*curr_ = curr;
        ListNode*prev_ = prev;
	
	    //reverse
	    for(int i=left;i<=right;i++){
		    ListNode*t = curr_->next;
		    curr_->next = prev_;
		    prev_=curr_;
		    curr_=t;
	    }
	
	    //connect
	    prev->next = prev_; //(left-1)->next  to right
	    curr->next = curr_; //left  to right->next basically
	
	    return dummy->next;
    }
};