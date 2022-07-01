class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,ml=0,mr=0,ans=0;
        while(l<=r)
        {
            if(h[l]<=h[r])
            {
                if(h[l]>=ml)ml=h[l];
                else ans+=ml-h[l];
                
                l++;
            }
            else
            {
                if(h[r]>=mr) mr=h[r];
                else ans+=mr-h[r];
                
                r--;
            }
        }
        return ans;
    }
};