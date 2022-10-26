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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* make(ListNode*head,ListNode*tail){
        if(head==tail) return NULL;
        if(head->next == tail) return new TreeNode(head->val);
        
        ListNode*t = head,*mid = head;
        while(t!=tail && t->next!=tail){
            mid=mid->next;
            t=t->next->next;
        }
        
        TreeNode*root = new TreeNode(mid->val);
        root->left = make(head,mid);
        root->right = make(mid->next,tail);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return make(head,NULL);
    }
};