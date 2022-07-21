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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root==NULL) return 0;
        int ans=1;
        q.push({root,0});
        while(!q.empty())
        {
            int sz = q.size();
            int mn =q.front().second;
            int first,last;
            for(int i=0;i<sz;i++)
            {
                long cur =q.front().second-mn;
                root=q.front().first;
                q.pop();
                if(i==0) first=cur;
                if(i==sz-1)last=cur;
                if(root->left)
                    q.push({root->left,2*cur+1});
                if(root->right)
                    q.push({root->right,2*cur+2});
            
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};