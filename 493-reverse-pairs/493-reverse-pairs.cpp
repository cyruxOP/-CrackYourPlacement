class Solution {
public:
    int merge(vector<int> &nums,int lo,int mid,int hi)
    {
        int cnt=0;
        int j= mid+1;
        for(int i=lo;i<=mid;i++)
        {
            while(j<=hi && nums[i]>2LL*nums[j])
                j++;
            cnt+= (j-(mid+1));
        }
        vector<int> temp;
        int l=lo,r=mid+1;
        while(l<=mid and r<=hi)
        {
            if(nums[l]<nums[r])
                temp.push_back(nums[l++]);
            else
                temp.push_back(nums[r++]);
        }
        while(l<=mid)
            temp.push_back(nums[l++]);
        while(r<=hi)
            temp.push_back(nums[r++]);
        for(int i=lo;i<=hi;i++)
            nums[i]=temp[i-lo];
        return cnt;  
    }
    
    
    
    int ms(vector<int> &nums,int lo,int hi)
    {
        if(lo>=hi) return 0;
        int mid = lo + (hi-lo)/2;
        int inv = ms(nums,lo,mid);
        inv += ms(nums,mid+1,hi);
        inv += merge(nums,lo,mid,hi);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};