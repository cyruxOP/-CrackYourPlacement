class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
         vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            long long target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                long long target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                      res.push_back({num[i],num[j],num[front],num[back]});
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == num[front+1]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == num[back-1]) --back;
                        front++;back--;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};