class Solution {
public:
    int dp[3000];
    vector<vector<int>> pal;
    int k;
    int f(int ind,int n)
    {
        if(ind==n)
            return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=0;
        for(int i=ind;i<n;i++)
        {
            if(i-ind+1>=k && pal[ind][i])
            {
                ans=max(ans,1+f(i+1,n));
            }
        }
        ans = max(ans,f(ind+1,n));
        return dp[ind]=ans;
    }
    
    int maxPalindromes(string s, int l) {
        int n = s.size();
        pal.clear();
        pal.resize(n,vector<int>(n,0));
        int ans=0;
        k=l;
        memset(dp,-1,sizeof(dp));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                    pal[i][j]=1;
                else if(g==1)
                    pal[i][j]=(s[i]==s[j]);
                else 
                {
                    if(s[i]==s[j] && pal[i+1][j-1]==1)
                        pal[i][j]=1;
                }    
            }
        }
      
        return f(0,n);
    }
};