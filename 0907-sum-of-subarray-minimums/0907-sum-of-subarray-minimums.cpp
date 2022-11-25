class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n,0),pos(n,0);
      
        stack<int> st1,st2;
        for(int i=0;i<n;i++)
        {
            pre[i]=i;
            pos[i]=n-i-1;
        }
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]>arr[i])
            {
                pos[st1.top()]=i-st1.top()-1;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]>=arr[i])
            {
                pre[st2.top()]=st2.top()-i-1;
                st2.pop();
            }
            st2.push(i);
        }
        int ans=0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++)
        {
            long long a = arr[i];
            a*= (pre[i]+1)%mod;
            a*= (pos[i]+1)%mod;
            ans+=a%mod;
            ans%=mod;
        }
        return ans;
    }
};