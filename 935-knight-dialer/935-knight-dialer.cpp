class Solution {
    public:
    const int M = 1e9+7;
    int f(int i,int n,vector<vector<int>>&states,vector<vector<int>>&dp)
    {
        if(n==0)
            return 1;
        int total=0;
        if(dp[i][n]!=-1) return dp[i][n];
        for(int j=0;j<states[i].size();j++)
        {
            total=(total+ f(states[i][j],n-1,states,dp))%M;
        }
        
       return dp[i][n]=total;
    }
    int knightDialer(int n) {
    vector<vector<int>> states=
    {{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{4,2}};
    vector<vector<int>> dp(10,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<10;i++)
        {
            ans = (ans+ f(i,n-1,states,dp))%M;
        }
        return ans;
    }
};