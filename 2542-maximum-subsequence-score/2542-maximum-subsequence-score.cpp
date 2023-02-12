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
        for(auto it1:res)
        {
            for(auto it:it1)
                cout<<it<<" ";
            cout<<'\n';
        }
        for(int i=0;i<nums1.size();i++)
        {
            pq.push(res[i][1]);
            cur+=res[i][1];
            if(pq.size()>k)
            {
                cur-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            ans=max(ans,1ll*cur*res[i][0]);
           
        }
        return ans;
            
    }
};