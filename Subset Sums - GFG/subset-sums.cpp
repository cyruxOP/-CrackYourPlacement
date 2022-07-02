// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
   void fun(vector<int> &arr,int N,int idx,int sum,vector<int> &res)
   {
   if(idx==N)
   {
   res.push_back(sum); return;
   }
   sum+=arr[idx];
   fun(arr,N,idx+1,sum,res);
   sum-=arr[idx];
   fun(arr,N,idx+1,sum,res);
}
  vector<int> subsetSums(vector<int> arr,int N)
  {
  vector<int> res;
  fun(arr,N,0,0,res);
  sort(res.begin(),res.end());
  return res;
  }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends