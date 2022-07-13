class Solution {
public:
    int bb(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int tk = nums[ind] + bb(ind-2,nums,dp);
        
        int nt = 0 + bb(ind-1,nums,dp);
        
        return dp[ind]= max(tk,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
       return bb(n-1,nums,dp);
    }
};