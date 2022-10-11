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
       
            int n  = nums.size();
      vector<int> temp;
	temp.push_back(nums[0]);int ln=1;
	for(int i=1;i<n;i++)
	{
		if(nums[i]>temp.back())
		{
			temp.push_back(nums[i]);
			ln++;
		}else
		{
			int ind  = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
			temp[ind]=nums[i];
		}
	}
	return ln>=3;
        return 0;
    }
};