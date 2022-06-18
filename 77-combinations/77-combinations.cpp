class Solution {
public:
    
    void gs(int s,int n,vector<int>&curr, vector<vector<int>> &ans,int k)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=s;i<=n;i++)
        {
            curr.push_back(i);
            gs(i+1,n,curr,ans,k);
            curr.erase(curr.begin()+(curr.size()-1));
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        gs(1,n,curr,ans,k);
        return ans;
    }
};