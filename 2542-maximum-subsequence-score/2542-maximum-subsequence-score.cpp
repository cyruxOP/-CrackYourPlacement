class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        vector<vector<int>> res;
        long long cur=0;
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back({nums2[i],nums1[i]});
        }
        sort(res.begin(),res.end(),greater<vector<int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        // for(auto it1:res)
        // {
        //     for(auto it:it1)
        //         cout<<it<<" ";
        //     cout<<'\n';
        // }
        int sz=0;
        for(int i=0;i<nums1.size();i++)
        {
            pq.push(res[i][1]);
            cur+=res[i][1];
            sz++;
            if(sz>k)
            {
                cur-=pq.top();
                pq.pop();
                sz--;
            }
            if(sz==k)
            ans=max(ans,1ll*cur*res[i][0]);
           
        }
        return ans;
            
    }
};