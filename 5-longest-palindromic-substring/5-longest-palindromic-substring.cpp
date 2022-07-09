class Solution {
public:
    int ln (string &s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
          i--,j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int st=0,e=1;
        for(int i=0;i<s.size();i++)
        {
            int l1 = ln(s,i,i); int l2;
            if(i<s.size()-1 && s[i] == s[i+1])
                l2 = ln(s,i,i+1);
            else l2=0;
            int len = max(l1,l2);
            if(e<len)
            {
              st=i- (len/2);
             if(!(len&1))
             {st=i-(len/2)+1;}
              e=len;
            }
            
        }
        return s.substr(st,e);
    }
};