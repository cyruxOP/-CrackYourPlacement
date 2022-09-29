class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-1;
        while(r-l+1>k)
        {
            if(x-arr[l]<=arr[r]-x)r--;
            else l++;
        }
        return vector<int>(begin(arr) + l, begin(arr) + r + 1);
    }
};