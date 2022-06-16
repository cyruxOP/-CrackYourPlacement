class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=-1;
        int l=0,r= height.size()-1;
       int area;
           while(l<r)
        {
             area= (r-l) * min(height[l],height[r]);
            if(area > mx)
                mx= area;
            if(height[l]<height[r])
                l++;
            else r--;
        }
        return mx;
    }
};