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
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        int ans= f(n-1,tar,arr,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};