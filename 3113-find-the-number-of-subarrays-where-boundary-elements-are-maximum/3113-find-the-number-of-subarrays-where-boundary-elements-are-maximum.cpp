class Solution {
public:
    using ll = long long;
    long long numberOfSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<int> st;
        vector<int> nge(n,n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                nge[i]=n;
            }else{
                nge[i]=st.top();
            }
            
            st.push(i);
        }
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(nge[i]);
        }
        ll ans = 0;
        
        for(auto it:mp){
            int l =-1;
            ll cnt =0;
      
            for(auto i:it.second){
          
                if(l==-1){
                    l=i;
                    cnt++;
                    continue;
                }
                
                if(i!=l){
                    ans+= (cnt* (cnt+1))/2;
                    cnt=1;
                }
                else{
                    cnt++;
                }
                l=i;
            }
              ans += (cnt * (cnt+1))/2;
   
            
          
            
        }
        
        return ans;
    }
};