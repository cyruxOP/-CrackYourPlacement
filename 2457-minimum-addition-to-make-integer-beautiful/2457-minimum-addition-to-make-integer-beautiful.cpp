class Solution {
public:
    void update(vector<int>&num,long long n,int &sum)
    {
        int c = num.size()-1;
        while(n)
        {
            int ld = n%10;
            sum+=ld;
            num[c]=ld;
            c--;
            n/=10;
        }
    }
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> nums(14,0);
            int sum=0;
        update(nums,n,sum);
        if(sum<=target)
            return 0;
      
        // cout<<sum;
        vector<int> res;
        // // for(int a:nums)
        // // {
        // //     cout<<a<<" ";
        // }
        for(int i=13;i>=0;i--)
        {
            if(nums[i]==10 || nums[i]==0)
            {
                if(nums[i]==10)
                {
                    sum-=9;
                    nums[i]=0;
                    nums[i-1]++;
                    if(sum<=target)
                        break;
                    res.push_back(0);

                }
                  else if(nums[i]==0)
                {
                      
                 res.push_back(0);
                if(sum<=target)
                    break;
                }
            }
            else
            {
                sum-=nums[i];
                sum++;
                cout<<sum<<" ";
                res.push_back(10-nums[i]);
                  nums[i]=0;
                nums[i-1]++;
                if(sum<=target)
                    break;
            }
        }
        long long ans=0;
        int k=res.size();
        long long x=1,i=0;
        
        while(i<k)
        {
            ans+=res[i++]*x;
            x*=10;
        }
        return ans;
        
    }
};