class Solution {
public:
    vector<string>ans;
    bool check(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                if(s[i]!='(') return 0;
                st.push(s[i]);
            }
            else if(!st.empty())
            {
                if(st.top()=='(' and s[i]==')')
                {
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return st.empty();
    }
    void fn(int n,string s)
    {
        if(s.size()>=n*2)
        {
            if(check(s)) ans.emplace_back(s);
             return;   
        }   
        
        fn(n,s+'(');
        fn(n,s+')');
            
    }
    vector<string> generateParenthesis(int n) {
        string s;
        fn(n,s);
        return ans;
    }
};