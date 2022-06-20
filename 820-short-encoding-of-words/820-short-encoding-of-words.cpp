class Solution {
public:
    int minimumLengthEncoding(vector<string>& v) {
        unordered_set<string>st(begin(v),end(v));
        for(auto &w:st)
        {
            string g=w;
            for(int i=1;i<g.size();i++)
            {
                string t=g.substr(i);
              
                if(st.find(t)!=st.end()){
                st.erase(t);
                }
                
            }
            
        }
        int res{};
        for(auto &i:st)
        {
            res+=(i.size()+1);
        }
        return res;
    }
};