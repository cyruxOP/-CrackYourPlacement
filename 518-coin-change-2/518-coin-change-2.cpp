class Solution {
public:
    int f(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return tar%arr[0]==0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int nt = f(ind-1,tar,arr,dp);
        int tk =0;
        if(arr[ind]<=tar)
            tk = f(ind,tar-arr[ind],arr,dp);
        
        return dp[ind][tar]=nt+tk;
        
    }
    int change(int tar, vector<int>& arr) {
        int n =arr.size();
        vector<int> prev(tar+1,0),  curr(tar+1,0);
        for(int t=0;t<=tar;t++)
        
            if(t%arr[0]==0) prev[t]=1;
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=tar;t++)
            {
                int nt = prev[t];
                int tk =0;
                if(arr[i]<=t)
                    tk=curr[t-arr[i]];
                
                curr[t]= nt+tk;
            }
            prev=curr;
        }
        return prev[tar];
    }
};