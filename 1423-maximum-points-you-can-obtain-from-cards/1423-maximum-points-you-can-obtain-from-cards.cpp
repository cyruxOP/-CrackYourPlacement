class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
     int l=0,r=cp.size()-1-k;
        int sum=0,mx=0;
        for(int i=r+1;i<cp.size();i++)
        {
            sum+=cp[i];
        
        }
        mx=sum;
        cout<<sum<<" ";
    while(r<cp.size()-1)
    {
        r++;
        sum-=cp[r];
        sum+=cp[l];
        cout<<sum<<" ";
        l++;
        mx = max(sum,mx);
    }
        return mx;
    }
};