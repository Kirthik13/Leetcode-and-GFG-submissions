class Solution {
public:
    string removeDuplicates(string s) {
        vector<char>st;
        
        for(auto &i:s)
        {
            if(!st.empty())
            {
                if(st.back()==i)
                {
                    st.pop_back();
                }
                else{
                st.push_back(i);
                    
                }
            }
            else{
                st.push_back(i);
            }
        }
        string ans;
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};