class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        int sum=0;
        if(num==k) return 1;
        int l=num%10;
        for(int i=1;i<=10;i++)
        {
            sum+=k;
            cout<<sum;
            if(sum%10==l){
            
                if(sum>num)
                    return -1;
                else return i;
            }
        }
        return -1;
    }
};