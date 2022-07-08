class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(),i=0,j=0,lind=0;
        reverse(s.begin(),s.end());
        while(j<n)
        {
            while(j<n && s[j]==' ')
                j++;
            int sind=i;
            while(j<n && s[j]!=' ')
            {
                s[i++]=s[j++];
                    lind=i;
            }
            reverse(s.begin()+sind,s.begin()+lind);
            s[i++]=' ';
        }
        s.resize(lind);
        return s;
    }
};