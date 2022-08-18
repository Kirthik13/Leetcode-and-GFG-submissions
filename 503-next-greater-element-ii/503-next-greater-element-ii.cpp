class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        vector<int>st;
        
        vector<int>ans(n,-1);
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<n;i++)
            {
                while(!st.empty() and v[st.back()]<v[i])
                {
                    ans[st.back()]=v[i];
                    st.pop_back();
                }
                st.push_back(i);
            }
        }
        return ans;
    }
};