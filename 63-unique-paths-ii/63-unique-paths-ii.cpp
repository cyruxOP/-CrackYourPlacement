class Solution {
public:
    int f(int m,int n ,vector<vector<int>>&ob,vector<int> &dp)
    {
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(ob[i][j]==1)dp[j]=0;
                else if(i==0 && j==0) temp[j]=1;
                else
                {
                    int up=0,lf=0;
                     if(i>0)up = dp[j];
                     if(j>0)lf = temp[j-1];
                    temp[j]=up+lf;
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m =ob.size(),n=ob[0].size();
        vector<int> dp(n,0);
        return f(m,n,ob,dp);
    }
};