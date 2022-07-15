class Solution {
public:
    int f(int ind,int tar,vector<int>&arr,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(tar%arr[ind]==0) return tar/arr[ind];
            return 1e9;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int nt = 0 + f (ind-1,tar,arr,dp);
        int tk = INT_MAX;
           if(arr[ind]<=tar)
             tk= 1 + f(ind,tar-arr[ind],arr,dp);
        return  dp[ind][tar]=min(tk,nt);
        
    }
    int coinChange(vector<int>& arr, int tar) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        for(int t=0;t<=tar;t++)
        {  if(t%arr[0]==0) dp[0][t]= t/arr[0];
        else dp[0][t] = 1e9;
         
        }
        for(int i=1;i<n;i++)
            for(int t=0;t<=tar;t++)
            {
                int tk = 0 + dp[i-1][t];
                int nt = INT_MAX;
                if(arr[i]<=t)
                  nt=  1 + dp[i][t-arr[i]];
                dp[i][t]=min (tk,nt);
                
            }
        
        return (dp[n-1][tar]>=1e9)?-1:dp[n-1][tar];
    }
};