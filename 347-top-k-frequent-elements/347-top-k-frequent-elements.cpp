class cmp{
    public:
    bool operator()(pair<int,int>&a , pair<int,int>&b)
    {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        for(auto x:mp)
        {
           pq.push(x);
            if(pq.size()>k)
                pq.pop();
            
        }
        vector<int> ans;
        while(pq.size())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};