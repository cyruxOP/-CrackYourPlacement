class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,ans=0;
        map<int,int> mp;
        mp[0]=1;
        for(auto it:nums)
        {
            sum+=it;
            int f = sum-k;
            if(mp.find(f)!=mp.end())
            {
                ans+=mp[f];
            }
            mp[sum]++;
            
        }
        return ans;
    }
};