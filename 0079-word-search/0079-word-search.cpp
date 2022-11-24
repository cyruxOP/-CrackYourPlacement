class Solution {
public:
    bool dfs(int i,int j,int ind,vector<vector<char>> &board,vector<vector<int>>&vis,string&word)
    {
         vis[i][j]=1;
        if(ind==word.size()-1) return 1;
        int dx[][2]={{-1,0},{0,1},{1,0},{0,-1}};
        for(int k=0;k<4;k++)
        {
            int x = i+dx[k][0];
            int y = j+dx[k][1];
            if(x>=0 && y>=0 && x<vis.size() && y<vis[0].size() && !vis[x][y] && word[ind+1]==board[x][y]){
            if(dfs(x,y,ind+1,board,vis,word)) return 1;
            vis[x][y]=0;
            }
        }
        return 0;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int s =word.size();
        int m = board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    if(dfs(i,j,0,board,vis,word)) return 1;
                }
            }
        }
        return 0;
    }
};