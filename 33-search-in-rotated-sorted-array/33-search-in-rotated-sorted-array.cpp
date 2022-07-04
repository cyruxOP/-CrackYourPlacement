class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int lo=0,hi=nums.size()-1;
        int ind =-1;
        while(lo<=hi)
        {
            int mid= (lo+hi) /2;
            if(nums[mid]==tar)
            { ind=mid;
                break;
            }  
            if(nums[lo]<=nums[mid])
            {
                if(tar>=nums[lo] && tar<=nums[mid])
                    hi=mid-1;
                else
                    lo=mid+1;
            }
            else
            {
                if(tar>=nums[mid] && tar<=nums[hi])
                {
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
        }
        return ind;
    }
};