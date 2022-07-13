class Solution {
public:
    int s(vector<int>&nums,int s,int e)
    {
        int prev = nums[s];
        int prev2=0;
        for(int i=s+1;i<=e;i++)
        {
            int tk=nums[i] + prev2;
            int nt=0 + prev;
            int curr= max(tk,nt);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int a= s(nums,0,n-2);
        int b = s(nums,1,n-1);
        return max(a,b);
    }
};