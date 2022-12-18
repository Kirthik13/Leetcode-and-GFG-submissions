class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
      vector<int>st;
        int n=v.size();
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and v[st.back()]<v[i])
            {
                ans[st.back()]=i-st.back();
                st.pop_back();
                
            }
                st.push_back(i);
            
        }
        
        return ans;
    }    
};