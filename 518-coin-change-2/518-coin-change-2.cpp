class Solution {
public:
    int f(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return tar%arr[0]==0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int nt = f(ind-1,tar,arr,dp);
        int tk =0;
        if(arr[ind]<=tar)
            tk = f(ind,tar-arr[ind],arr,dp);
        
        return dp[ind][tar]=nt+tk;
        
    }
    int change(int tar, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>> dp(n,vector<int> (tar+1,-1));
        return f(n-1,tar,coins,dp);
    }
};