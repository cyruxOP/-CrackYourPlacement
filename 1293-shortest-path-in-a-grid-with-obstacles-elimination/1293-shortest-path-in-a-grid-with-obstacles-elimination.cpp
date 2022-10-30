class Node{
    public:
    int cr;
    int cc;
    int sp;
    Node(int r,int c,int s)
    {
        cr=r;
        cc=c;
        sp=s;
    }
};


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        if(m==1 && n==1)
            return 0;
        queue<Node> q;
        q.push(Node(0,0,k));
        vector<vector<int>> mxSup(m,vector<int>(n,-1));
        mxSup[0][0]=k;
        int lvl=0;
        while(!q.empty())
        {
            int sz=q.size();
            lvl++;
            while(sz--)
            {
                Node cur = q.front();
                q.pop();
                int dx[][4]={{-1,0},{0,1},{1,0},{0,-1}};
                for(int i=0;i<4;i++)
                {
                    int nx = cur.cr+dx[i][0];
                    int ny = cur.cc+dx[i][1];
                    if(nx ==m-1 && ny==n-1)
                        return lvl;
                    if(nx<m && ny<n && nx>=0 && ny>=0)
                    {
                        if(grid[nx][ny]==1 && cur.sp>0 && mxSup[nx][ny]<cur.sp-1)
                        {
                            q.push({nx,ny,cur.sp-1});
                            mxSup[nx][ny]=cur.sp-1;
                        }
                        else if(grid[nx][ny]==0 && mxSup[nx][ny]<cur.sp)
                        {
                            q.push({nx,ny,cur.sp});
                            mxSup[nx][ny]=cur.sp;
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};