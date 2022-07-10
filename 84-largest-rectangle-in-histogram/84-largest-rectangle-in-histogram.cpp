class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n =h.size();
        stack<int> st;
        int sl[n],sr[n];
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {
                st.pop();
            }
                if(st.size())
                {
                    sl[i]=st.top()+1;
                }
                else sl[i]=0;
                st.push(i);
            
        }
        while(st.size())
            st.pop();
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {
                 st.pop();

             }
           if(st.size())
            sr[i]=st.top()-1;
          else sr[i]=n-1;
        ans = max(ans,h[i]* (sr[i]-sl[i]+1)*1LL);
            st.push(i);
        }
        
        
        return 	ans;
    }
};