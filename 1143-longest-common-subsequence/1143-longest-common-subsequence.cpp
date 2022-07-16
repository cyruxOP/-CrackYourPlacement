class Solution {
public:
    int f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= 1 + f(i-1,j-1,s1,s2,dp);
    
        return dp[i][j]= max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(),n=s2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=1;
                    if(i>0 && j>0)
                    dp[i][j]+=dp[i-1][j-1];
                }
                else
                {
                    int f=0;
                    if(i>0) f=dp[i-1][j];
                    int s=0;
                    if(j>0) s=dp[i][j-1];
                    dp[i][j]= max(f,s);
                }
            }
        return dp[m-1][n-1];
    }
};