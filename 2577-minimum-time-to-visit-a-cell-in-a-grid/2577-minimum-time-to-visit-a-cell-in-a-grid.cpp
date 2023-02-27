class Solution {
public:
    class Node{
        public:
        int time,r,c;
        
        Node(int t,int r,int c)
        {
            time=t;
            this->r=r;
            this->c=c;
        }
        
        bool operator<(const Node&rhs) const
        {
            if(rhs.time!=time) return time<rhs.time;
            if(rhs.r!=r) return r<rhs.r;
            return c<rhs.c;
        }
    };
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(grid[1][0]>1 && grid[0][1]>1)
            return -1;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        set<Node> q;
        q.insert(Node(grid[0][0],0,0));
        dist[0][0]=0;
        int dir[][2]= {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty())
        {
            
            Node cur = *(q.begin());
            q.erase(q.begin());
            int cx = cur.r;
            int cy = cur.c;
            for(auto i:dir)
            {
                int nx = cx + i[0];
                int ny = cy + i[1];
                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;
                int wt = max(0,grid[nx][ny]- cur.time-1);
                if(wt&1)
                    wt++;
                int nt = cur.time + wt + 1;
                if(dist[nx][ny]>nt)
                {
                    q.insert(Node(nt,nx,ny));
                    dist[nx][ny]=nt;
                }
            }
        }
        return dist[m-1][n-1];
    }
};