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
    int maxLevelSum(TreeNode* root) {
         queue<TreeNode*> q;int l=0,mx=INT_MIN,ml=1;
        if(!root) return 0;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            l++;int sum=0;
            while(k--)
            {
                root=q.front();
                q.pop();
                sum+=root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                
            }
            if(sum>mx)
            {
                ml=l;
                mx=sum;
            }
        }
        return ml;
    }
};