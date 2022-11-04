class Solution {
public:
      bool is(char c)
   {
       if(c=='A' || c=='E' || c=='I'  || c=='O' || c=='U') return 1;
       if(c=='a' || c=='e' || c=='i'  || c=='o' || c=='u') return 1;
       return 0;
   }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(!is(s[i]) && i<j)
                i++;
            while(!is(s[j]) && i<j)
                j--;
            if(i>=j) break;
            swap(s[i],s[j]);
            i++,j--;
        }
     
        return s;
    }
};