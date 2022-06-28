class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1=-1,num2=-1,c1=0,c2=0;
        for(int el: nums)
        {
            if(el==num1) c1++;
            else if(el==num2) c2++;
            else if(c1==0)
            {
                num1=el;
                c1=1;
            }
            else if(c2==0)
            {
                num2=el;
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        int x=0,y=0;
        for(int el:nums)
        {
            if(el==num1) x++;
            else if(el==num2) y++;
        }
        vector<int> ans;
        if(x>(n/3)) ans.push_back(num1);
        if(y>(n/3)) ans.push_back(num2);
        return ans;
     }
};