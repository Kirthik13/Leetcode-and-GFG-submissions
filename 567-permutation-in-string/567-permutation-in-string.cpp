class Solution {
public:
    bool contains(string &s1,unordered_map<char,int> &m1, unordered_map<char,int> &m2)
    {
        if(m1==m2) return 1;
        return 0;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return 0;
        if(s1.size()==1)
        {
            if(s2.size()==1)
            {
                return (s1[0]==s2[0])?1:0;
            }
            auto it=s2.find(s1[0]);
            if(it!=string::npos)
            {
                return 1;
            }
            return 0;
            
        }
        unordered_map<char,int>m1;
        for(auto &i:s1)
        {
            m1[i]++;
        }
        int window=s1.size();
        unordered_map<char,int>m2;
        for(int i=0;i<window;i++)
        {
            m2[s2[i]]++;
        }
        if(contains(s1,m1,m2)) return 1;
        
        for(int i=window;i<s2.size();i++)
        {
            m2[s2[i]]++;
            m2[s2[i-window]]--;
            if(m2[s2[i-window]]==0)
            {
                m2.erase(s2[i-window]);
            }
            if(contains(s1,m1,m2))
            {
                return 1;
            }
        }
        return 0;
    }
};