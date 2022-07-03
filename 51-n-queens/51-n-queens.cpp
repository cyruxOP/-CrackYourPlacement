class Solution {
public:
    
    bool is(int row,int col,vector<string>&vs,int n)
    {
        int r=row,c=col;
        while(row>=0 && col>=0)
        {
            if(vs[row][col]=='Q') return false;
            row--,col--;
        }
        row=r,col=c;
        while(col>=0)
        {
            if(vs[r][col]=='Q') return false;
            col--;
        }
        col=c;
        while(row<n && col>=0)
        {
            if(vs[row++][col--]=='Q') return false;
            
        }
        return true;
    }
    
    void bt(int col,vector<vector<string>> &ans, vector<string> &vs,int n)
    {
        if(col==n)
            ans.push_back(vs);
        
        for(int rows=0;rows<n;rows++)
        {
            if(is(rows,col,vs,n))
               {
                   vs[rows][col]='Q';
                   bt(col+1,ans,vs,n);
                   vs[rows][col]='.';
               }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> vs;
        string s(n,'.');
        for(int i=0;i<n;i++)
            vs.push_back(s);
        bt(0,ans,vs,n);
        return ans;
        
    }
};