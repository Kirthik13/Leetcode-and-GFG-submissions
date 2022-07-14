class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int>st;
        int n=v.size(),ans{};
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() and (i==n or v[st.top()]>=v[i]))
            {
                int height=v[st.top()],width;
                st.pop();

                if(st.empty()){
                 width=i;
                }
                else{
                    width=i-st.top()-1;
                }

                ans=max(ans,height*width);
            }
            st.push(i);
        }
        return ans;
    }
};