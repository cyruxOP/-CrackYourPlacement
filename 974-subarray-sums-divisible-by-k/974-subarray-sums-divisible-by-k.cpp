class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int s=0;
        vector<int> v(k,0);
        int ans=0;
        v[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            int a = s % k;
            if(a<0)
                a+=k;
            ans+=v[a];
             v[a]++;
        }
        return ans;
        
    }
};