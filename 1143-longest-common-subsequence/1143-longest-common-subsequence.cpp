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
        vector<int> prev(m,0),curr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(s1[i]==s2[j])
                {
                    curr[j]=1;
                    if(i>0 && j>0)
                    curr[j]+=prev[j-1];
                }
                else
                {
                    int f=0;
                    if(i>0) f=prev[j];
                    int s=0;
                    if(j>0) s=curr[j-1];
                    curr[j]= max(f,s);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};