class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
        int cp=0,cm=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            
            if(prices[i]<cm)
                cm=prices[i];
            ans= max(ans,prices[i]-cm);
            
        }
        return ans;
    }
};