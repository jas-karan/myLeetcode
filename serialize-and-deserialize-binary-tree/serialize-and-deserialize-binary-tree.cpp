/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "X";
        string ser=to_string(root->val);
        
        ser+=","+serialize(root->left);
        ser+=","+serialize(root->right);
        
        return ser;
    }

    
    TreeNode* decode(string &data){
        if(data[0]=='X'){
            if(data.length()>1) data=data.substr(2);
            return NULL;
        }
        int val = helper(data);
        TreeNode*root=new TreeNode(val);
        root->left=decode(data);
        root->right=decode(data);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        return decode(data);
    }
    
    int helper(string&data){
        int comma = data.find(',');
        int val = stoi(data.substr(0,comma));
        data=data.substr(comma+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));