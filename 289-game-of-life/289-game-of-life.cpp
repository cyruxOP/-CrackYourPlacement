class Solution {
public:
    int chk(vector<vector<int>>& board,int a,int b,int m,int n)
    {
        int cnt=0;
        for(int i= max(a-1,0);i<= min(a+1,m-1);i++)
            for(int j= max(b-1,0);j<=min(b+1,n-1);j++)
            {
                if(i==a && j==b) continue;
                if(board[i][j]==1 || board[i][j]==2) cnt++;
            }
        return cnt;
                
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        //0 -> 0 0
        //1 -> 1 1
        //1 -> 0 2
        //0 -> 1 3
        
        int m = board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                // int c=3;
                int c = chk(board,i,j,m,n);
                if(board[i][j]==1)
                {
                    if(c<2 || c>3)
                        board[i][j]=2;
                    else board[i][j]=1;
                }else 
                {
                    if(c==3)
                        board[i][j]=3;       
                }
                
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==2)
                    board[i][j]=0;
                else if(board[i][j]==3)
                    board[i][j]=1;
            }
    }
};