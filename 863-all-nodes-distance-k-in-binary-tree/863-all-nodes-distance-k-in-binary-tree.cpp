/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int x) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) return ans;
        q.push(root);
        map<TreeNode*,TreeNode*> mp;
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                root=q.front();
                q.pop();
                if(root->left)
                {
                    q.push(root->left);
                    mp[root->left]=root;
                }
                if(root->right)
                {
                    q.push(root->right);
                    mp[root->right]=root;
                }
            }
        }
        int t=0;
        unordered_set<TreeNode*> st;
        q.push(target);
        st.insert(target);
        while(t!=x)
        {
          int qs=q.size();
            while(qs--)
            {
                root=q.front();
                q.pop();
                if(root->left && !st.count(root->left))
                {
                    q.push(root->left);
                    st.insert(root->left);
                }
                if(root->right && !st.count(root->right))
                {
                    q.push(root->right);
                    st.insert(root->right);
                }
                if(mp.find(root)!=mp.end() && !st.count(mp[root]))
                {
                    q.push(mp[root]);
                    st.insert(mp[root]);
                }
            }
            t++;
        }
        
        cout<<q.size();
        while(!q.empty())
            {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};