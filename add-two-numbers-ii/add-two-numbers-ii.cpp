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
    ListNode* add(ListNode*l1, ListNode*l2,int&carry){
        if(!l1) return NULL;
        
        ListNode* node = add(l1->next,l2->next,carry);
        ListNode*cur = new ListNode();
        cur->next=node;
        cur->val = (carry+l1->val+l2->val)%10;
        carry = (carry+l1->val+l2->val)/10;
        
        return cur;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p1=l1,*p2=l2;
        
        while(p1||p2){
            if(!p1){
                ListNode*node=new ListNode(0);
                node->next = l1;
                l1=node;
                p2=p2->next;
            }
            else if(!p2){
                ListNode*node=new ListNode(0);
                node->next = l2;
                l2=node;
                p1=p1->next;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }
        }
        int carry=0;
        ListNode* head = add(l1,l2,carry);
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next=head;
            head=node;
        }
        
        return head;
    }
};