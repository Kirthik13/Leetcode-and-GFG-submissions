class Solution {
public:
    bool canConstruct(string s, string t) {
        map<char,int>m;
        for(auto &i:t) m[i]++;
        
        for(auto &i:s)
        {
            if(m.find(i)==m.end()) return 0;
            
            if(m[i]==1) m.erase(i);
            else m[i]--;
        }
        return 1;
    }
};