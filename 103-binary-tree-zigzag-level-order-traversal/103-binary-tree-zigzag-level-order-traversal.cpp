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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        int flag=1;
        while(!q.empty())
        {
            int k=q.size();
            vector<int> temp(k);
            for(int i=0;i<k;i++)
            {
                root=q.front();
                q.pop();
                if(flag)
                {
                    temp[i]=root->val;
                }
                else
                    temp[k-i-1]=root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            flag= (0==flag);
            ans.push_back(temp);
        }
        return ans;
    }
};