class DSU{
    public:
  int *par;
  int N;
  vector<int> rank;
    
    DSU(int n)
    {
        N=n;
        par = new int[n];
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank.push_back(0);
        }
    }
    
    int fndPar(int node)
    {
        if(node!=par[node])
            par[node]=fndPar(par[node]);
        return par[node];
    }
    void unn(int u,int v)
    {
        int p1 = fndPar(u);
        int p2 = fndPar(v);
        
        if(p1==p2) return;
    
        
            par[p2]=p1;
            N--;
        
    }
    
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        DSU ds(n);
        map<int,int> rm,cm;
        for(int i=0;i<n;i++)
        {
           int r = stones[i][0];
           int c = stones[i][1];
           if(!rm.count(r))rm[r]=i;
           if(!cm.count(c))cm[c]=i;
           ds.unn(rm[r],i);
           ds.unn(cm[c],i);
        }       
        
        return n - ds.N;
    }
    
    bool is(vector<int>&a ,vector<int>&b)
    {
        return a[0]==b[0] || a[1]==b[1];
    }
};;