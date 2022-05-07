class Solution {
public:
    bool find132pattern(vector<int>& v) {
        stack<int>st;
        int n=v.size();
        int f=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]<f) return 1;
            while(!st.empty() and st.top()<v[i])
            {
                f=st.top();
                st.pop();
            }
            st.push(v[i]);
        }
        return 0;
    }
};
