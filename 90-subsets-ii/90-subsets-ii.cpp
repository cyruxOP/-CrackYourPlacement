class Solution {
public:
   void sum(int ind, vector<vector<int>> &ans, vector<int> &nums,vector<int> &temp,int n)
    {
      ans.push_back(temp);
       for(int i=ind;i<n;i++)
       {
           if(i!=ind && nums[i]==nums[i-1]) continue;
           temp.push_back(nums[i]);
           sum(i+1,ans,nums,temp,n);
           temp.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        sum(0,ans,nums,temp,nums.size());
        return ans;
        
        
    }
};