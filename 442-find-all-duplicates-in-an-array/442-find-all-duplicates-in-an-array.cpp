class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int j=1;
        for(int i=0;i<nums.size();i++)
        {
            int ind = abs(nums[i])-1;
            if(nums[ind]<0) ans.push_back(abs(nums[i]));
            nums[ind]*=-1;
        }
        return ans;
    }
};