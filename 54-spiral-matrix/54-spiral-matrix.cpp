class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        vector<int> ans;
        int left=0,right=n,top=0,bot=m;
        while(left<right && top<bot)
        {
            for(int i=left;i<right;i++)
            ans.push_back(mat[top][i]);
            top++;
            for(int i=top;i<bot;i++)
            ans.push_back(mat[i][right-1]);
            right--;
            
            if (!(left<right && top<bot))
                break;
            for(int i=right-1;i>=left;i--)
                ans.push_back(mat[bot-1][i]);
                bot--;
            for(int i=bot-1;i>=top;i--)
                ans.push_back(mat[i][left]);
            left++;
            
            
        }
        return ans;
        
    }
};