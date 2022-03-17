class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans{};
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else{
               
                int res{};
                while(st.top()!=-1)
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                res==0?st.push(1):st.push(2*res);
                // cout<<st.top();
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            // cout<<"ans : "<<ans;
            st.pop();
        }
        return ans;
    }
};