class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        vector<int>st;
        
        vector<int>ans(n,-1);
        // for(int j=0;j<2;j++)
        // {
            for(int i=0;i<2*n;i++)
            {
                while(!st.empty() and v[st.back()]<v[i%n])
                {
                    ans[st.back()]=v[i%n];
                    st.pop_back();
                }
                st.push_back(i%n);
            }
        // }
        return ans;
    }
};