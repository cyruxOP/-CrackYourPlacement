class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
    vector<vector<int>> res;
        for(int i=0;i<p.size();i++)
        {
            res.push_back({g[i],p[i]});
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        int time =0,mx=0;
        for(auto it:res)
        {
            int gt = it[0];
            int pt = it[1];
            time+=pt;
            mx = max(mx,time+gt);
        }
        return mx;
    }
};