class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m= mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
            dp[0][j]=mat[0][j];
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int lf = mat[i][j] ;
                if(j>0)
                lf+=dp[i-1][j-1];
                else 
                lf+=1e9;
                int rt = mat[i][j] ;
                if(j+1<n)
                rt+=dp[i-1][j+1];
                else 
                rt+=1e9;
                int up = mat[i][j] + dp[i-1][j];
                
                dp[i][j]= min(lf,min(rt,up));
            }
        }
        int mn =INT_MAX;
        for(int j=0;j<n;j++)
            mn = min(dp[m-1][j],mn);
        return mn;
    }
};