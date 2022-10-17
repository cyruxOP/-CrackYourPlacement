class Solution {
public:
    vector<int>arr;
    vector<vector<int>> g;
    int dfs(int ind,int par,const int tar)
    {
        int val = arr[ind];
        for(auto it:g[ind])
        {
            if(it==par)continue;
            val+=dfs(it,ind,tar);
        }
        if(val==tar) return 0;
        return val;
    }
    
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        g.clear();arr.clear();
        int n = nums.size();
        g.resize(n);
        arr.resize(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            arr[i]=nums[i];
        }
        for(auto it:edges)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        int result=0;
        for(int p=sum;p>=1;p--)
        {
            if(sum%p!=0)continue;
            if(dfs(0,-1,sum/p)!=0) continue;
            return p-1;
        }
        return 0;
    }
};