class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int s=0,e= n*m-1;
        while(s<=e)
        {
            int mid = s+ (e-s)/2;
            int el = matrix[mid/n][mid%n];
            if(el==target)
            {
                return true;
            }
            else if(el<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return false;
    }
};