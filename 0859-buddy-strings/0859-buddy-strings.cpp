class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() ) return 0;
        int cnt{};
        map<char,int>m;
        int pos1=-1,pos2=-1;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            if(s[i]!=g[i])
            {
                cnt++;
                if(pos1==-1)
                {
                    pos1=i;
                }
                else{
                    pos2=i;
                }
            }
        }
        
        if(cnt!=2) 
        {
         
            if(cnt==0)
            {
                for(auto &i:m)
                {
                    if(i.second>1) return 1;
                }
            }
            return 0;
        }
        swap(s[pos1],s[pos2]);
        return g==s;
    }
};