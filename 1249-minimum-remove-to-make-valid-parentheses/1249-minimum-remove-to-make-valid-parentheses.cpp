class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        // string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='(' and s[i]!=')')
            {
                // ans.push_back(i);
                continue;
            }
            if(st.empty())
            {
                st.push({s[i],i});
            }
            else{
                if(st.top().first=='(' and s[i]==')')
                {
                    st.pop();
                }
                else{
                    st.push({s[i],i});
  
                }
            }
            // cout<<st.size()<<endl;
        }
        deque<char>ans;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!st.empty())
            {
                // cout<<st.top().first<<" "<<st.top().second<<endl;
                if(st.top().second==i)
                {
                    st.pop();
                    continue;
                }
                ans.push_front(s[i]);
            }
            else{
                                ans.push_front(s[i]);

            }
        }
        string res(ans.begin(),ans.end());
        return res;
    }
};