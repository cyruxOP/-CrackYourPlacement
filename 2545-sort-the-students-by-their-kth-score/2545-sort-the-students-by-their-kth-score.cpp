 int kk;
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[kk]>b[kk];
    }
    

class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        kk=k;
       sort(score.begin(),score.end(),cmp);
        return score;
    }
};