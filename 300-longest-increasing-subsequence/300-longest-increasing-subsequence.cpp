class Solution {
public:
    
    int f(int i,int pi,int &n,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int len = f(i+1,pi,n,nums,dp);
        
        if(pi==-1 || nums[i]>nums[pi])
        len = max(len,1+f(i+1,i,n,nums,dp));
        return dp[i][pi+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);int l=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                l++;
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) -temp.begin();
                temp[ind]=nums[i];
            }
        }
        return l;
        
    }
};