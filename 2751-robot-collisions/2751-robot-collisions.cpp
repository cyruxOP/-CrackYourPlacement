class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string str) {
        int n = healths.size();
        
        stack<int> st;
        vector<vector<int>> srt;
          map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            srt.push_back({positions[i],str[i]=='R' ? 1:0,healths[i]});
            mp[positions[i]]=healths[i];
        }
        sort(srt.begin(),srt.end());
        string s = "";
        for(int i=0;i<n;i++)
        {
            s.push_back(srt[i][1]==1?'R' : 'L');
        }

        for(int i=0;i<n;i++)
        {
            
           
            if(st.empty())
            {
                if(s[i]=='R')
                    st.push(i);
                continue;
            }
            
            if(s[i]=='L')
            {
                while(!st.empty() && mp.find(srt[i][0])!=mp.end())
                {
                int a = st.top();
                if(mp[srt[a][0]]>mp[srt[i][0]])
                {
                    mp[srt[a][0]]--;
                    mp.erase(srt[i][0]);
                  break;
                    // cout<< mp[pos[a][0]];
                }
                else if(mp[srt[i][0]] == mp[srt[a][0]])
                {
                    mp.erase(srt[a][0]);
                    mp.erase(srt[i][0]);
                    st.pop();
                    break;
            
                }
                else
                {
                    st.pop();
                    mp.erase(srt[a][0]);
                    mp[srt[i][0]]--;
                }
                      
                      
                      }
            }
            else
            {
                st.push(i);
            }
                     
        }
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(mp[positions[i]]>0)
                res.push_back(mp[positions[i]]);
        }
        return res;
        
    }
};