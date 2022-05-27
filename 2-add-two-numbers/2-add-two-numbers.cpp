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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ans = new ListNode();
        ListNode*temp = ans;
        
        int carry=0;
        
        while(l1||l2||carry){
            int curr=0;
            if(l1){
                curr+=l1->val;
                l1=l1->next;
            }
            if(l2){
                curr+=l2->val;
                l2=l2->next;
            }
            if(carry) curr+=carry;
            
            ListNode*digit = new ListNode(curr%10);
            carry = curr/10;
            temp->next = digit;
            temp= temp->next;
        }
        
        return ans->next;
    }
};