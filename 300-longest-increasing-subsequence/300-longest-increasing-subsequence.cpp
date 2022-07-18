class Solution {
public:
    
    int f(int i,int pi,int &n,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int len = f(i+1,pi,n,nums,dp);
        
        if(pi==-1 || nums[i]>nums[pi])
        len = max(len,1+f(i+1,i,n,nums,dp));
        return dp[i][pi+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};