class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        if(s.size()!=t.size()) return 0;
        for(int i=0;i<s.size();i++)
        {
            if(m1.size()>0 and m2.size()>0)
            {
                if(m1.find(s[i])!=m1.end() or m2.find(t[i])!=m2.end())
                {
                    if(m1[s[i]]!=t[i]) return 0;
                    if(m2[t[i]]!=s[i]) return 0;
                }
            }
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        return 1;
    }
};