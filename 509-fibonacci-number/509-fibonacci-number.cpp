class Solution {
public:
    int f(int n,vector<int>&dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int l = f(n-1,dp);
        int r = f(n-2,dp);
        
        return dp[n]= l+r;
    }
    int fib(int n) {
        vector<int> dp(31,-1);
        return f(n,dp);
    }
};