class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> v;
        for(int i=1;i<n;i++)
        { fact*=i;
          v.push_back(i);
        }
        k--;
        v.push_back(n);
        string ans ="";
        while(true)
        {
            ans = ans + to_string(v[k/fact]);
            v.erase(v.begin() + k/fact);
            if(v.size()==0)
                return ans;
            k%=fact;
            fact/=v.size();
        }
        
    }
};