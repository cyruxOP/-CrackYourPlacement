class Solution {
public:
       void sum(int ind,int target,vector<vector<int>> &ans,vector<int> &can,vector<int> temp,int n)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind==n) return;
        if(target-can[ind]>=0){
            temp.push_back(can[ind]);
        sum(ind+1,target-can[ind],ans,can, temp,n);
        temp.pop_back();}
        
        while(ind+1<n && can[ind]==can[ind+1])
            ind++;
        sum(ind+1,target,ans,can,temp,n);
       }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
         vector<vector<int>> ans;
        vector<int> temp;
        sort(can.begin(),can.end());
        sum(0,target,ans,can, temp,can.size());
        return ans;
    }
};