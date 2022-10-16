class Solution {
public:
    int rev(int n)
    {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    
    
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return 1;
        for(int i=num/2;i<=num;i++)
        {
            int r = rev(i);
            if(i+r==num) return 1;
        }
        return 0;
    }
};