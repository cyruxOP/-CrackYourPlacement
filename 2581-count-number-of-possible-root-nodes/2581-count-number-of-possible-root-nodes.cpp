class Solution {
public:
    void euler(int i,vector<int>adj[],vector<int>&vis,int &ind,vector<int>&start,vector<int>&end,vector<int>&et,vector<int>&par)
    {
        vis[i]=1;
        start[i]=ind;
        et[ind]=i;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                ind++;
                par[it]=i;
                euler(it,adj,vis,ind,start,end,et,par);
            }
        }
        end[i]=ind;
    }
    
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;
        vector<int> adj[n];
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> et(n),start(n),end(n),vis(n,0),res(n+1,0),par(n,0);
        int ind=0;
        euler(0,adj,vis,ind,start,end,et,par);
        

        for(auto it:guesses)
        {
            int u = it[0];
            int v = it[1];
        
            
            if(par[v]==u)
            {
            res[0]++;
            int l1 = start[v];
            int r2 = end[v]+1;
            res[l1]--;
            res[r2]++;
            }
            else
            {
                int l1 = start[u];
                int r2= end[u]+1;
                res[l1]++;
                res[r2]--;
            }
        }
        for(int i=1;i<=n;i++)
        res[i]=res[i]+res[i-1];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(res[i]>=k)
                ans++;
        }
        
        return ans;
    }
};