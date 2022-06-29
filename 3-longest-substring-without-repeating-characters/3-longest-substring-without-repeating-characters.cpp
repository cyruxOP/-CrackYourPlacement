class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,len=0;
        int n = s.size();
        while(r<n)
        {
            if(mp.find(s[r])!=mp.end())
            {
                l=max(l,mp[s[r]]+1);
                mp[s[r]]=r;
            }
          mp[s[r]]=r;
            len=max(len,r-l+1); 
            cout<<l<<" "<<r<<" "<<endl;
            r++;
        }
        return len;
    }
};