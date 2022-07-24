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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int ,int> inmp;
        int p=postorder.size(),q=inorder.size();
        for(int i=0;i<q;i++)
            inmp[inorder[i]]=i;
        TreeNode* root = bt(inorder,0,q-1,postorder,0,p-1,inmp);
            
        return root;
    }
    TreeNode* bt(vector<int>&ino,int ins,int ine,vector<int>&pos,int ps,int pe, map<int,int>&inmp)
    {
        if(ins>ine || ps>pe) return NULL;
        int inr = inmp[pos[pe]];
        int left = inr-ins;
        
        TreeNode* root= new TreeNode(pos[pe]);
        
        root->left=bt(ino,ins,inr-1,pos,ps,ps+left-1,inmp);
        root->right=bt(ino,inr+1,ine,pos,ps+left,pe-1,inmp);
        return root;
    }
};