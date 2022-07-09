class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
     	mp['V']=5;
        mp['X']=10;
        mp['L'] =50;
        mp['C']=100;
    	mp['D']=500;
        mp['M']=1000;
        int n= s.size();
        int res=mp[s[n-1]];
        for(int i=n-2;i>=0;i--)
        {
            char c =s[i],d=s[i+1];
            if(mp[c]<mp[d])
            res-= mp[c];
            else
            res+=mp[c];
        }
        return res;
    }
};