class Solution {
public:
    int trap(vector<int>& v) {
        stack<int>st;
        int n=v.size();
        int ans{};
        for(int i=0;i<n;i++)
        {
           
            while(!st.empty() and v[st.top()]<v[i])
            {
                int dig=v[st.top()];
                st.pop();
           
                if(!st.empty())
                {
                    int leftidx=v[st.top()];
                    int minheight=min(leftidx,v[i]);
                    int width=i-st.top()-1;
                    ans+=(minheight-dig)*width;
                }
            }
            st.push(i);
            
        }
        return ans;
    }
};