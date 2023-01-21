class Solution {
public:
    long long minOperations(vector<int>& n1, vector<int>& n2, int k) {
        long long up=0,down=0;
        long long car=0;
        int n = n1.size();
        vector<long long> nums1(n) ,nums2(n);
        for(int i=0;i<n;i++)
        {
            if(n1[i]!=n2[i]){
            int dif = abs(n1[i]-n2[i]);
            if( k==0 || dif%k!=0 )
                return -1;
            if(n1[i]>n2[i])down+=dif/k;
            else up+=dif/k;
            }
        }
     return up==down?up:-1;
    }
};