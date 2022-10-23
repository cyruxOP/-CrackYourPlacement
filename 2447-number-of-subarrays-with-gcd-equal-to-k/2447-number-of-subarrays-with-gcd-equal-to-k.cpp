class Solution {
public:
    int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
    int subarrayGCD(vector<int>& nums, int k) {
        int n =nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int cur = nums[i];
            for(int j=i;j<n;j++)
            {
                cur = gcd(cur,nums[j]);
                if(cur==k)cnt++;
            }
        }
        return cnt;
    }
};