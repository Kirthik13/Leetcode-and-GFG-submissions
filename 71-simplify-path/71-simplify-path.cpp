class Solution {
public:
    string simplifyPath(string s) {
     stack<string>st;
    stringstream ss(s);
        string tem;
        vector<string>v;
        while(getline(ss,tem,'/'))
        {
               v.push_back(tem);
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()==0 or v[i]==".") continue;
            else if(v[i]==".." )
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else{
                st.push(v[i]);
            }
        
        }
        string ans;
        while(!st.empty())
        {
            ans=st.top()+"/"+ans;
            st.pop();
        }
        return ans.size()==0?"/":"/"+ans.substr(0,ans.size()-1);
    }
};