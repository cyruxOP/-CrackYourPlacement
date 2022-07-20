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
    int ms(TreeNode* root,int &mx)
    {
        if(root==NULL)
            return 0;
        int ls = max(0,ms(root->left,mx));
        int rs = max(0,ms(root->right,mx));
        mx = max(root->val+ls+rs,mx);
        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
       ms(root,mx);
        return mx;
    }
};