class Solution {
public:
//     int fn(vector<int>&v,int idx,int &k,vector<int>&dp)
//     {
//         if(idx>=v.size()-1) return -1e5;
//         if(idx==v.size()-1) return v[idx];
        
//         if(dp[idx]!=-1) return dp[idx];
        
//         int ans=INT_MIN;
//         int dest=idx+k;
//         for(int i=idx+1;i<=dest;i++)
//         {
//             int g=fn(v,i,k,dp);
//             g+=v[idx];
            
//             ans=max({ans,g});
//         }
//         return dp[idx]=ans;
//     }
    int maxResult(vector<int>& v, int k) {
        vector<int>dp(v.size(),INT_MIN);
        int n=v.size();
        
        multiset<int>st;
        dp[n-1]=v[n-1];
        st.insert(v[n-1]);
        for(int idx=n-2;idx>=0;idx--)
        {
          if(st.size()>k)
          {
              auto it=st.find(dp[idx+k+1]);
              st.erase(it);
          }
          dp[idx]=max(*st.rbegin()+v[idx],dp[idx]);
          st.insert(dp[idx]);
            
        }
        
        return dp[0];
        // return fn(v,0,k,dp);
    }
};