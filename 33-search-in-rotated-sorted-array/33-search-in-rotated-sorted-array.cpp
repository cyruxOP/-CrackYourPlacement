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
            if(tar==nums[0]) return 0;
            if(tar<nums[0])
            {
                if(nums[mid]>=nums[0])
                    lo=mid+1;
                else
                {
                    if(tar<nums[mid])
                        hi=mid-1;
                    else
                        lo=mid+1;
                } 
                    
            }
            else{
                if(nums[mid]>=nums[0])
                {
                    if(tar>nums[mid])
                        lo=mid+1;
                    else
                        hi=mid-1;
                }
                else
                    hi=mid-1;
            }
            cout<<lo<<" "<<hi<<endl;
        }
        return ind;
    }
};