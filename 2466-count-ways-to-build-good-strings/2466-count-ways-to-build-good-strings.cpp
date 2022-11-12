class Solution {
public:
    int mod =1e9+7;
    int f(int ind,int zc,int oc,vector<int>&dp)
    {
        if(ind<0) return 0;
        if(ind==0) return 1;
        if(dp[ind]!=-1) return dp[ind]%mod;
        int l = f(ind-zc,zc,oc,dp);
        int r = f(ind-oc,zc,oc,dp);
        
        return dp[ind]= (l+r)%mod;
    }
    
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int ans=0;
        vector<int> dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
         ans = (ans+f(i,zero,one,dp))%mod;   
        }
        
        return ans%mod;
    }
};