class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>&tr,vector<vector<int>>&dp)
    {
        if(i==n-1) return tr[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int dow = tr[i][j]+ f(i+1,j,n,tr,dp);
        int dg =tr[i][j] + f(i+1,j+1,n,tr,dp);
        
        return dp[i][j]= min(dow,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,m,triangle,dp);
    }
};