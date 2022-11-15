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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = lfh(root);
        int rh = rgh(root);
        
        if(lh==rh) return (1<<lh) -1;
        
        return 1 + countNodes(root->left)+countNodes(root->right);
        
    }
    int lfh(TreeNode* node)
    {
        int ans=0;
        while(node)
        {
            ans++;
            node=node->left;
        }
        return ans;
    }
    int rgh(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->right;
        }
        return ans;
    }
};