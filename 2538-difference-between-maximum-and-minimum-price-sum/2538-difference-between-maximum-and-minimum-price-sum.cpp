typedef long long ll;
class Solution {
vector<vector<int>> g;
vector<ll> max_down,max_up;
vector<ll> prices;
public:
    ll downDfs(int cur,int par)
    {
        ll &res=max_down[cur];
        
        for(auto i:g[cur])
        {
            if(i==par)
                continue;
            res=max(res,downDfs(i,cur));
        }
        res+=prices[cur];
        return res;
    }
    
    void upDfs(int src,int par)
    {
          multiset<ll> in_of_all;
        for (auto i : g[src]) {
            if (i == par) continue;
            in_of_all.insert(max_down[i]);
        }
        
        for (auto i : g[src]) {
            if (i == par) continue;
            ll cur_val = max_down[i];
            
            in_of_all.erase (in_of_all.find(cur_val));
            
            ll below = in_of_all.empty()? 0 : *(--in_of_all.end());
            max_up[i] = max (below, max_up[src]) + prices[src];
            
            in_of_all.insert (cur_val);
            upDfs (i, src);
        }
    }
    
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        g.clear(),max_down.clear(),max_up.clear(),prices.clear();
        g.resize(n);
        max_down.resize(n);
        max_up.resize(n);
        prices.resize(n);
        for(int i=0;i<n;i++)
            prices[i]=price[i];
        for(auto e:edges)
        {
               g[e[0]].push_back(e[1]);
               g[e[1]].push_back(e[0]);
        }
        downDfs(0,-1);
        upDfs(0,-1);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll cur_mn=prices[i];
            ll cur_mx=max(max_down[i],max_up[i]+prices[i]);
            ans=max(ans,cur_mx-cur_mn);
        }
        return ans;
        
    }
};