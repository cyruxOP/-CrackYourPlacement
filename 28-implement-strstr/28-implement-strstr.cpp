class Solution {
public:
    int strStr(string h, string n) {
        
        for(int i=0;i<h.size();i++)
            {
            int j=0;
            int si=i;
            while(j<n.size() )
                {
                if(h[si]==n[j]){
                    si++;j++;
                    continue;
                    }
                else
                    break;
            }
            if(j==n.size())
                return i;
        
        }
        return -1;
    }
};