class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0) return 1.00;
       double ans = 1.00;
     long long nn = n;
      if(nn<0) nn = -1 * nn;
        
      while(nn)
            {
                if(nn%2){
                ans*=x;
                nn--;
                }
               else
               {
                   x = x * x;
                   nn/=2;
               }
          
            }
        
    if(n<0) ans = 1.00/ans;
        return ans;
        
        
        
        
    }
};