class Solution {
public:
    int f(int m,int n,vector<vector<int>>&dp)
    {
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {dp[i][j]=1;continue;}
                int l=0,r=0;
                if(j>0) l = dp[i][j-1];
                if(i>0) r = dp[i-1][j];
                
              dp[i][j]=l+r;
            }
        }
        return dp[m-1][n-1];
    
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        return f(m,n,dp);
    }
};