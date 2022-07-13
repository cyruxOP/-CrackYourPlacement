class Solution {
public:
    int f(int m,int n,vector<int>&dp)
    {
        
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {temp[j]=1;continue;}
                int l=0,r=0;
                if(j>0) l = temp[j-1];
                if(i>0) r = dp[j];
                
              temp[j]=l+r;
            }
            dp=temp;
        }
        return dp[n-1];
    
    }
    
    int uniquePaths(int m, int n) {
        vector<int>dp;
        return f(m,n,dp);
    }
};