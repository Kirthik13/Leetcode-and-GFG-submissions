class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) return 0;
        unordered_map<char,int>m1,m2;
        set<char>st1;
        set<char>st2;
        for(auto &i:s1)
        {
            m1[i]++;
            st1.insert(i);
        }
        for(auto &i:s2)
        {
            m2[i]++;
                st2.insert(i);

        }
        if(st1!=st2) return 0;
        for(auto &i:m1)
        {
            int c=i.second;
            char ch=i.first;
            int f=0;
            for(auto &j:m2)
            {
                if(j.second==c)
                {
                    m2.erase(j.first);
                    f=1;
                    break;
                }
                
            }
            if(!f) return 0;
                
        }
        return 1;
        
    }
};