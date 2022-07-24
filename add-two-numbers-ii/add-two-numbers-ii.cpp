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
        stack<ListNode*>s1,s2,s3;
        ListNode*dummy=new ListNode();
        ListNode*prev=dummy;
        
        while(l1||l2){
            if(l1){
                s1.push(l1);
                l1=l1->next;
            }
            if(l2){
                s2.push(l2);
                l2=l2->next;
            }
            ListNode*node = new ListNode();
            prev->next=node;
            prev=node;
            s3.push(node);
        }
        
        int carry=0;
        while(!s1.empty() || !s2.empty()){
            int sum=carry;
            if(s1.size()){sum+=s1.top()->val; s1.pop();}
            if(s2.size()){sum+=s2.top()->val; s2.pop();}
            
            s3.top()->val = sum%10;
            carry = sum/10;
            s3.pop();
        }
        
        ListNode*head=dummy->next;
        if(carry){
            ListNode*node = new ListNode(carry);
            node->next=head;
            head=node;
        }
        
        return head;
    }
};