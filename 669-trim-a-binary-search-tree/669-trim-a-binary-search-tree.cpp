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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(root->val>=low && root->val<=high){
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
        }
        else if(root->val<low){ //then whole left subtree would be trimmed
            return trimBST(root->right,low,high);
        }
        else return trimBST(root->left,low,high);  //whole right subtree would be trimmed
        
        return root;
    }
};