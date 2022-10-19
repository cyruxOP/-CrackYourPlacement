class cmp{
    public:
    bool operator()(pair<int,string>&a,pair<int,string>&b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto x:words)
            mp[x]++;
        int sz=0;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
            sz++;
            if(sz>k)
            {
                pq.pop();
                sz--;
            }
        }
        vector<string> ans;
        while(!pq.empty())
        {
            string s = pq.top().second;
            ans.push_back(s);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};