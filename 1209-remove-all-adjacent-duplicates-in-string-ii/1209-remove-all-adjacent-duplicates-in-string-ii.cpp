class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
         if(st.empty() || st.top().first!=s[i])st.push({s[i],1});
            else
            {
                auto p =st.top();
                st.pop();
                if(p.second+1!=k)
                    st.push({s[i],p.second+1});
            }
            
        }
        string ans="";
        while(!st.empty())
        {
            int n = st.top().second;
            while(n--)
                ans.push_back(st.top().first);
            st.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};