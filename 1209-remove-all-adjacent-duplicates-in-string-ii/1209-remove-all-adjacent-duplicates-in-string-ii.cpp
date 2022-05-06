class Solution {
public:
    string removeDuplicates(string s, int k) {
     string ans;
        stack<pair<int,char>>st;
        for(auto i:s)
        {
            if(st.empty())
            {
                st.push({1,i});
            }
            else{
                if(st.top().second==i)
                {
                    st.top().first++;
                    if(st.top().first==k) 
                    {
                        st.pop();
                    }
                }
                else{
                    st.push({1,i});

                }
                
            }
        }
        while(!st.empty())
        {
            char ch=st.top().second;
            int nos=st.top().first;
            // while(nos--)
            // {
                ans.insert(ans.begin(),nos,ch);
            // }
            st.pop();
        }
        // std::reverse(begin(ans),end(ans));
        return ans;
    }
};