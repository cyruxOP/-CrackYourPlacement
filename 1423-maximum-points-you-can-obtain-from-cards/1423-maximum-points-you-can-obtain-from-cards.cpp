class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
     int l=0,r=cp.size()-k;
        int sum=0,mx=0;
        for(int i=r;i<cp.size();i++)
        {
            sum+=cp[i];
        
        }
        mx=sum;
        cout<<sum<<" ";
    while(r<cp.size())
    {
        sum+=(cp[l]-cp[r]);
        mx = max(sum,mx);
        l++;r++;
    }
        return mx;
    }
};