// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>> &m,string tmp,vector<string> &ans,int di[],int dj[])
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(tmp);
            return;
        }
        string d ="DLRU";
        for(int t=0;t<4;t++)
        {
            int ni = i+di[t];
            int nj = j+dj[t];
            if(ni<n && nj<n && ni>=0 && nj>=0 && m[ni][nj]==1)
            {
                m[i][j]=0;
                solve(ni,nj,n,m,tmp+d[t],ans,di,dj);
                m[i][j]=1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        int di[] ={1,0,0,-1};
        int dj[] ={0,-1,1,0};
        if(m[0][0]==1)solve(0,0,n,m,"",ans,di,dj);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends