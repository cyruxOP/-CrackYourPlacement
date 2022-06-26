class Solution {
public:
    
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long su) {
        int m =sp.size(),n=po.size();
        vector<int> ans(m,0);
        
        sort(po.begin(),po.end());
        for(int i=0;i<m;i++)
        {
            int lo=0,hi=n-1;
            int ai=-1;
            while(lo<=hi)
            {
                int mid = (hi+lo)/2;
                long pro = (long)sp[i] * (long)po[mid];
                if(pro>=su)
                {
                    ai=mid;
                    hi=mid-1;
                }else
                {
                   lo=mid+1;
                }
            }
            if(ai!=-1)
                ans[i]=n-ai;
        }
        return ans;
    }
};