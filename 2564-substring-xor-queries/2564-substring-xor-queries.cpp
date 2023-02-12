class Solution {
public:
    int dec(int l,int r,const string&s)
    {
        int ans=0;
        int pw=1;
        for(int i=r;i>=l;i--)
        {
            if(s[i]=='1')
                ans+=pw;
            pw*=2;
        }
        return ans;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
    map<int,vector<int>> mp;
    int n = s.size();
    for(int sub =1;sub<31;sub++)
    {
        for(int i=0;i+sub-1<n;i++)
        {
            int val = dec(i,i+sub-1,s);
            if(mp.find(val)!=mp.end())continue;
            mp[val]={i,i+sub-1};
            
        }
    }
        vector<vector<int>> res;
        
     for(int i=0;i<q.size();i++)
     {
         int val = q[i][0]^q[i][1];
         if(mp.find(val)==mp.end())res.push_back({-1,-1});
         else
             res.push_back(mp[val]);
         
     }
        return res;
    }
};