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

    void code(TreeNode*root, string &ser){

        ser+=to_string(root->val);
        
        if(root->left){
            ser+='L';
            code(root->left,ser);
        }
        else{
            ser+='X';
        }
        if(root->right){
            ser+='R';
            code(root->right,ser);
        }
        else{
            ser+='X';
        }
        
    }
    
    string serialize(TreeNode* root) {
        string ser = "";
        if(!root) return ser;
        code(root,ser);
        cout<<ser;
        return ser;
    }

    
    TreeNode* decode(string&data){
        int i=0;
        int val=0;
        bool neg=false;
        if(data[i]=='-'){neg=true; i++;}
        while(data[i]>='0'&&data[i]<='9'){
            val=val*10+(data[i]-'0');
            i++;
        }
        TreeNode*root = new TreeNode(0);
        if(neg) val*=-1;
        root->val=val;
        data=data.substr(i);
        
        if(data[0]=='L'){
            data=data.substr(1);
            root->left = decode(data);
        }
        else{
            data=data.substr(1);
            root->left=NULL;
        }
        if(data[0]=='R'){
            data=data.substr(1);
            root->right=decode(data);
        }
        else{
            data=data.substr(1);
            root->right=NULL;
        }
        
        return root;
        
    }
    
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        TreeNode*root = decode(data);
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));