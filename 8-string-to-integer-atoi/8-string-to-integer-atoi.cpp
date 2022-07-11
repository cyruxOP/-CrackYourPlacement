class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ')
            i++;
        int sign=1;
        if(s[i]=='-'){sign=-1;i++;}
        if(s[i]=='+'){ 
            i++;
        if(sign==-1) return 0;}
        long long ans=0;
        while(i<s.size())
        {
            if(s[i]<'0' || s[i]>'9')
                break;
            if(s[i]==' '){i++;continue;}
            ans = (ans * 10) + (s[i]-'0');
            cout<<ans<<" ";
            if(ans*sign<INT_MIN) return INT_MIN;
            if(ans*sign>INT_MAX) return INT_MAX;
            i++;
        }
        return ans*sign;
    }
};