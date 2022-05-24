class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty())
                {
                    if(s[st.top()]=='(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if(st.empty()) ans=n;
        else{
            int a=n,b{};
            while(!st.empty())
            {
                b=st.top();
                st.pop();
                ans=max(ans,a-b-1);
                a=b;
                
            }
            ans=max(ans,a);

        }
        return ans;
    }
};