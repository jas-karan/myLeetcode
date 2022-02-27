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
    int cameras = 0;
    
    int helper(TreeNode* root){
        if(root == NULL) return 1;  //for null => already covered so no new camera will be installed
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        //does left or right need camera then i have to install camera on this node
        if(l==-1 || r==-1){
            cameras++;
            return 0;  //since i installed a camera, so i have a camera
        }
        
        if(l==0 || r==0) return 1; //since any of child have a camera, so i am covered
        
        return -1; //neither i am covered nor i installed a new camera so i need a camera
    }
    
    int minCameraCover(TreeNode* root) {
        //-1 if node needs a camera
        //0 if node has a camera
        //1 if node is covered
        //we will not install camera on leaf, rather on its parent
        //so that parent and leaves will be covered by one camera
        //so leaves will pass -1 to its parent saying that I need a camera
        
        if(helper(root)==-1) cameras++;
        
        return cameras;
    }
};