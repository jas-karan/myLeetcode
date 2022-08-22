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
int maxVal = 0;
int longestConsecutive(TreeNode* root) {
    if(root == nullptr) return 0;
    dfs(root, {1,1});
    return maxVal;
}

pair<int,int> dfs(TreeNode* root, pair<int, int> cur){
    pair<int,int> l(0,0);
    pair<int,int> r(0,0);
    if(root->left){
        l = dfs(root->left, {1,1});
        if(root->left->val + 1 == root->val){
            cur.first += l.first;
        }
        if(root->left->val - 1 == root->val){
            cur.second += l.second;
        }
    }
    if(root->right){
        r = dfs(root->right, {1,1});
        if(root->right->val + 1 == root->val){
            cur.first = max(cur.first, r.first + 1);
        }
        if(root->right->val - 1 == root->val){
            cur.second = max(cur.second, r.second + 1);
        }
    }
    maxVal = max(maxVal, cur.first + cur.second - 1);
    return cur;
}
};