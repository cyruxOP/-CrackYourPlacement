class Solution {
public:
    string minWindow(string s, string t) {
         int mn=INT_MAX;
        map<char,int> mp;
        for(char c:t)
        mp[c]++;
        int r,l;
        int n= s.size(),cnt=mp.size();
        int i=0,j=0;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            if(cnt>0) j++;
            else 
            {
               if(j-i+1<mn)
               {
                   l=i;r=j;mn=j-i+1;
               }
                while(cnt==0)
                {
                    if(mp.find(s[i])==mp.end())
                    {
                        i++;
                        if(j-i+1<mn)
                        {
                            l=i;r=j;mn=j-i+1;
                        }
                    }
                    else
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                        {
                            i++;
                            cnt++;
                        }
                        else
                        {
                            i++;
                            if(j-i+1<mn)
                        {
                            l=i;r=j;mn=j-i+1;
                        }
                        }
                    }
                }
                j++;
            }
        }    
        
        if(mn==INT_MAX) return "";
        return s.substr(l,r-l+1);
    }
};