class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int f=0;
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else
            {
                int res{};
                while(st.top()!=-1)
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                res==0?st.push(1):st.push(2*res);
               
            }
        }
        while(!st.empty())
        {
            c+=st.top();
            st.pop();
        }
        return c;
    }
};