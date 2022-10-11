class Solution {
public:
    int f(int i,vector<int>&nums,int cnt,int prev,vector<vector<vector<int>>>&dp)
    {
        if(cnt==3)
            return 1;
        if(i==nums.size()) return 0;
        if(dp[i][cnt][prev]!=-1) return dp[i][cnt][prev] ;
        int tk = 0;
        if(cnt==0  || (cnt<3 && nums[i]>prev))
        {
            tk = f(i+1,nums,cnt+1,nums[i],dp);
        }
       int  nt = f(i+1,nums,cnt,prev,dp);
        return dp[i][cnt][prev] = tk|nt;
    }
    
    bool increasingTriplet(vector<int>& nums) {
       
        int left=INT_MAX,mid=INT_MAX;
        for(int el:nums)
        {
            if(el>mid)
                return 1;
            else if(el<mid && el>left)
                mid=el;
            else if(el<left)
                left=el;
                
        }
        return 0;
    }
};