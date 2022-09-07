class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        
        for(auto &i:s) m1[i]++;
        for(auto &i:t) m2[i]++;
        
        int cnt{};
        for(auto &i:m1)
        {
            if(m1[i.first]>m2[i.first])
            {
            cnt+=abs(m1[i.first]-m2[i.first]);
            }
        }
        
        return cnt;
        
        
    }
};