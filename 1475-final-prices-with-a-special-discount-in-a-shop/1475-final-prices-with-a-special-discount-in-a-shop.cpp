class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        vector<int>st;
        int n=v.size();
        vector<int>ans(v.size());
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and v[st.back()]>v[i])
            {
                st.pop_back();
            }
            if(!st.empty())
            {
                ans[i]=v[i]-v[st.back()];
            }
            else{
                ans[i]=v[i];
            }
                
            st.push_back(i);
        }
        return ans;
    }
};