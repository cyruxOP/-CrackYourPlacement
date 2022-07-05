class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int lo=0,hi=n1;
        int med =( n1+n2+1)/2;
        while(lo<=hi)
        {
            int cut1 = (lo+hi)>>1;
            int cut2 = med - cut1;
            
            int l1 = (cut1==0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2==0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1==n1)?INT_MAX:nums1[cut1];
            int r2 = (cut2==n2)?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)&1)
                {
                    return max(l1,l2);
                }
                return ( max(l1,l2) + min(r1,r2))/2.00;
            }
            if(l1>r2) hi = cut1-1;
            else lo=cut1+1;
        }
        return 0.00;
    }
};