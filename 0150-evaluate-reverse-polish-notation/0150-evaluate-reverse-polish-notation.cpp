#define ll long long
class Solution {
public:
    bool isop(string &s)
    {
        if(s=="+" or s=="-" or s=="/" or s=="*") return 1;
        return 0;
    }
    int evalRPN(vector<string>& v) {
        vector<string>st;
        
        for(auto &i:v)
        {
            if(isop(i))
            {
                ll int b=stoll(st.back());
                st.pop_back();
                ll int a=stoll(st.back());
                st.pop_back();
                
                if(i=="+")
                {
                    ll int k=a+b;
                    string ans=to_string(k);
                    st.push_back(ans);
                }
               else if(i=="-")
                {
                    
                    ll int k=a-b;
                    string ans=to_string(k);
                    st.push_back(ans);
                    // st.push_back(a-b);
                }
               else if(i=="*")
                {
                    
                    ll int k=a*b;
                    string ans=to_string(k);
                    st.push_back(ans);
                    // st.push_back(a*b);
                }
               else 
                {
                    
                    ll int k=a/b;
                    string ans=to_string(k);
                    st.push_back(ans);
                    // st.push_back(a/b);
                }
            }
            else
            {
                st.push_back(i);
            }
        }
        
        return stoll(st.back());
    }
};