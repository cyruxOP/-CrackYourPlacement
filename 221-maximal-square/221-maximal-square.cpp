class Solution {
public:
    
    int topdown(vector<vector<char>>& matrix,int m,int n, vector<vector<int>> &dp,int &ans){
        if(m<0 || n<0) return 0;
        else if(dp[m][n]!=-1) return dp[m][n];
        else{
           
            if(matrix[m][n]=='1'){
                int left=topdown(matrix,m,n-1,dp,ans);
                int top=topdown(matrix,m-1,n,dp,ans);
                int corner=topdown(matrix,m-1,n-1,dp,ans);
                dp[m][n]=1+min(left,min(top,corner));
            }else{
                 int left=topdown(matrix,m,n-1,dp,ans);
                 int top=topdown(matrix,m-1,n,dp,ans);
                dp[m][n]=0;
            }
        }
        ans=max(ans,dp[m][n]);
        return dp[m][n];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=-1;
        int s = topdown(matrix,m-1,n-1,dp,ans);
        return ans* ans;
    }
};