class Solution {
public:
    bool isopen(char c)
    {
        if(c=='(' or c=='[' or c=='{') return 1;
        return 0;
    }
    int type(char c)
    {
        if(c=='(' or c==')') return 1;
             if(c=='[' or c==']') return 2;
        return 3;
    }
    bool isValid(string s) {
        if(s.size()==1) return 0;
            
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                if(isopen(s[i])) st.push(s[i]);
                else{
                return false;
                }
            }
            else if(!st.empty())
            {
                if(!isopen(s[i]))
                {
                    if(isopen(st.top()) and type(s[i])==type(st.top()))
                    {
                        st.pop();
                        // cout<<"ae";
                    }
                    else{
                    return false;
                    }
                    
                }
                else{
                        st.push(s[i]);
                    }
            }
        }
        return st.empty();
    }
};