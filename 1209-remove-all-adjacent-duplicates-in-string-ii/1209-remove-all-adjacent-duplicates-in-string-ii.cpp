class Solution {
public:
    string removeDuplicates(string s, int k) {
     string ans;
        vector<pair<int,char>>st;
        for(auto i:s)
        {
            if(st.empty())
            {
                st.push_back({1,i});
            }
            else{
                if(st.back().second==i)
                {
                    st.back().first++;
                    if(st.back().first==k) 
                    {
                        st.pop_back();
                    }
                }
                else{
                    st.push_back({1,i});

                }
                
            }
        }
        while(!st.empty())
        {
            char ch=st.back().second;
            int nos=st.back().first;
            while(nos--)
            {
                ans.push_back(ch);
            }
            st.pop_back();
        }
        std::reverse(begin(ans),end(ans));
        return ans;
    }
};