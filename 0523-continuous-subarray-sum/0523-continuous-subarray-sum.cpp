class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i =0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum%abs(k))!=mp.end())
            {
                int j = mp[sum%k];
                if(i-j>1) return 1;
            }
            else
            mp[sum%k]=i;
        }
        return 0;
    }
};