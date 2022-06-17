class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            
            int l=i+1,r=nums.size()-1,s=0-nums[i];
            while(l<r)
            {
               
               if(nums[l]+nums[r]==s)
               {
                   ans.push_back({nums[i],nums[l],nums[r]});
                   while(l<r && nums[l]==nums[l+1]) l++;
                   while(l<r && nums[r]==nums[r-1]) r--;
                   
                   l++;r--;  
               }
                else if(nums[l]+nums[r]<s) l++;
                else r--;
            }
            while(i+1<nums.size() and nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};