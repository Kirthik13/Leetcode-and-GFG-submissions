class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans;
        for(auto &i:s)
        {
            if(st.empty() and i=='(')
            {
                st.push(i);
            }
            else if(!st.empty() and i=='(')
            {
                st.push(i);
                ans+='(';
            }
            else if(st.size()>1 and i==')')
            {
                st.pop();
                ans+=')';
            }
            else if(st.size()==1 and i==')')
            {
                st.pop();
            }
        }
        return ans;
    }
};