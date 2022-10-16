class Solution {
public:
    int rev(int n)
    {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    
    
    bool sumOfNumberAndReverse(int num) {
      for(int i = 0; i <= num; ++i){
            int n = i;
            int r = 0;
            while(n){
                r = r*10 + n%10;
                n = n/10;
            }
            if(r + i == num) return true;
        }
        return false;
    }
};