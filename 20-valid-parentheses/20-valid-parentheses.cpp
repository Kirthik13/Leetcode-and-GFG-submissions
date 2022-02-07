int ord(char ch)
{
    if(ch=='(' or ch==')') return 1;
    if(ch=='{' or ch=='}') return 2;
    return 3;
    

}
bool isopen(char ch)
{
    return ch=='(' or ch=='{' or ch=='[';
}
bool isclose(char ch)
{
    return ch==')' or ch=='}' or ch==']';
}
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1) return 0;
            
        stack<char>st;
        for(auto &i:s)
            
        {
            
            if(st.empty())
            {
               
                if(isclose(i)) return 0;
                st.push(i);
            }
            else{
                if((ord(st.top())==ord(i)) and (isopen(st.top()) and isclose(i)))
                {
                    
                        // cout<<st.top()<<" "<<i<<endl;
                        st.pop();
                    // }
                }
                else{
                    st.push(i);
                }
            }
        }
        // cout<<st.size();
        return st.empty();
        
    }
};