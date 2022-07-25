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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string str;
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(!root)str.append("#,");
            else
            {
                str.append(to_string(root->val)+',');
                q.push(root->left);
                q.push(root->right);
            }
    
            
        }
        str.pop_back();
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* rot = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(rot);
        while(!q.empty())
        {
             TreeNode* root=q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#")
            {
                root->left=NULL;
            }
            else
            {
                root->left = new TreeNode(stoi(str));
                q.push(root->left);
            }
            getline(ss,str,',');
            if(str=="#")
                root->right=NULL;
            else
            {
                root->right=new TreeNode(stoi(str));
                q.push(root->right);
            }
            
            
        }
        return rot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));