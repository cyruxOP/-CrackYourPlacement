class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int el:nums)
            st.insert(el);
        int ans=0,cs=0,prev;
        for(int el:st)
        {
            if(el==prev+1)
            cs++;
            else
            {
                 ans= max(ans,cs);
                cs=0;
            }
            
            ans= max(ans,cs);
            
            prev=el;
        }
        if(st.empty()) return 0;
        return ans+1;
    }
};