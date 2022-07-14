class Solution {
public:
    int f(int m,int n,vector<vector<int>>&tr,vector<vector<int>>&dp)
    {
       for(int j=0;j<n;j++)
       {
           dp[m-1][j]=tr[m-1][j];
       }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int lf = tr[i][j] + dp[i+1][j];
                int dg = tr[i][j] + dp[i+1][j+1];
                
                dp[i][j]=min (lf,dg);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        return f(m,n,triangle,dp);
    }
};