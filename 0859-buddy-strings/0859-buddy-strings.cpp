class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() ) return 0;
        int cnt{};
        set<char>m;
        int pos1=-1,pos2=-1;
        for(int i=0;i<s.size();i++)
        {
            m.insert(s[i]);
            if(s[i]!=g[i])
            {
                if(pos1==-1)
                {
                    pos1=i;
                }
                else if(pos2==-1){
                    pos2=i;
                }
                else{
                    return 0;
                }
            }
        }
        
        if(pos1!=-1 and pos2!=-1)
        {
            return s[pos1]==g[pos2] and s[pos2]==g[pos1];
        }
        if(pos1!=-1) return 0;
        
        return m.size()<s.size();
//         if(cnt!=2) 
//         {
         
//             if(cnt==0)
//             {
//                 for(auto &i:m)
//                 {
//                     if(i.second>=2) return 1;
//                 }
//             }
//             return 0;
//         }
//         swap(s[pos1],s[pos2]);
//         return g==s;
    }
};