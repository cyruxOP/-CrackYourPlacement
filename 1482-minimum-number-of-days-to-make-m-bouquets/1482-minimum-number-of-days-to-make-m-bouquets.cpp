class Solution {
public:
    bool chk(int mid,int m,int k,vector<int> &nums)
    {
        int bq=0;
        int fl=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
                fl++;
            else fl=0;
            if(fl==k)
            {
                bq++;
                fl=0;
            }
            if(bq>=m)
                return true;
        }
        return false;
    }
    int minDays(vector<int>& bl, int m, int k) {
        int stu=m*k;
        if(stu>bl.size())
            return -1;
        int e=0;
        for(int i=0;i<bl.size();i++)
        {
            e=max(e,bl[i]);
        }
        int s=1,ans=-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(chk(mid,m,k,bl))
            {
                ans=mid;
                e=mid-1;
            
            }
            else
                s=mid+1;
        }
        return ans;
            
    }
};