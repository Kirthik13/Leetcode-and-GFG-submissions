class Solution {
public:
    int maxResult(vector<int>& v, int k) {
//         vector<int>dp(v.size(),INT_MIN);
//         int n=v.size();
        
//         multiset<int>st;
//         dp[n-1]=v[n-1];
//         st.insert(v[n-1]);
//         for(int idx=n-2;idx>=0;idx--)
//         {
//           if(st.size()>k)
//           {
//               auto it=st.find(dp[idx+k+1]);
//               st.erase(it);
//           }
//           dp[idx]=max(*st.rbegin()+v[idx],dp[idx]);
//           st.insert(dp[idx]);
            
//         }
        
//         return dp[0];
        
        deque<int>dq;
        int n=v.size();
        int curr=0;
        for(int i=0;i<n;i++)
        {
           curr=v[i]+(dq.empty()?0:v[dq.back()]);
           
            while(!dq.empty() and curr>v[dq.front()])
            {
                dq.pop_front();
                
            }
            dq.push_front(i);
            
            if(dq.back()+k<=i)
            {
                dq.pop_back();
                
            }
            
            v[i]=curr;
            
        }
        // return 
        return curr;
        
      
        
    }
};