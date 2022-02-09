class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return 1;
        if(s1.size()!=s2.size()) return 0;
        vector<int> c;
        int f=0;
        for(int i=0;i<s2.size();i++)
        {
            if(s1[i]!=s2[i]) c.push_back(i);
            if(c.size()==2)
            {
                if(s1[c.front()]==s2[i] and 
                s2[c.front()]==s1[i]) f=1;
            }
        }
        if(c.size()==2 and f==1) return 1;
        return 0;
    }
};