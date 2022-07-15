class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int ts=0;
        for(int i=0;i<nums.size();i++)
            ts+=nums[i];
        if(ts&1) return 0;
        ts/=2;
        int tar=ts;
        vector<vector<int>> dp(n,vector<int>(ts+1,0));
        for(int i=0;i<nums.size();i++)
            dp[i][0]=1;
        for(int i=0;i<n;i++)
            for(int t=1;t<=tar;t++)
            { 
                if(i==0)
                {
                    if(nums[0]==t) dp[0][t]=1;
                    continue;
                }
                int nt = dp[i-1][t];
                int tk = 0;
                if(nums[i]<=t)
                    tk=
                dp[i-1][t-nums[i]];
                
                dp[i][t]= nt | tk;
                
            }
        
        return dp[n-1][tar];
            
    }
};