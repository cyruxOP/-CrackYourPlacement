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
class two{
    public:
    int x;
    int y;
    

};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     vector<vector<int>> ans;
     if(!root) return ans;
     queue<pair<TreeNode*,two>> q;
        map<int,map<int,multiset<int>>>mp;
     two a;
        a.x=0,a.y=0;
     q.push({root,a});
        while(!q.empty())
        {
            int k =q.size();
            while(k--)
            {
                auto p=q.front();
                root=p.first;
                q.pop();
                two b =p.second;
                int l =b.x-1,r=b.x+1,dz=b.y+1;
                two fir;
                fir.x=l;
                fir.y=dz;
                two sec;
                sec.x=r;
                sec.y=dz;
                mp[b.x][b.y].insert(root->val);
                if(root->left)
                    q.push({root->left,fir});
                if(root->right)
                    q.push({root->right,sec});
                
                    
            }
        }
        for(auto it1:mp)
        {
            vector<int>temp;
            for(auto it2:it1.second)
            {
                temp.insert(temp.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};