class Solution {
public:
   void sum(int ind, vector<vector<int>> &ans, vector<int> &nums,vector<int> &temp,int n)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        sum(ind+1,ans,nums,temp,n);
        temp.pop_back();
       
        while(ind+1<n && nums[ind]==nums[ind+1])
            ind++;
       sum(ind+1,ans,nums,temp,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        sum(0,ans,nums,temp,nums.size());
        return ans;
        
        
    }
};