class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1,pro2=1,mx=INT_MIN,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            pro*=nums[i];
            pro2*=nums[n-i-1];
            mx = max(mx,pro);
            mx=max(mx,pro2);
            if(nums[i]==0)
            {
                pro=1;
            }
            if(nums[n-i-1]==0)
                pro2=1;
        }
     return mx;
    }
};