class Solution {
public:
    bool detectCapitalUse(string s) {
        int iscap{};
        for(auto &i:s) 
        {
            if(isupper(i)) iscap++;
        }
        
        if(iscap==s.size()) return 1;
        if(iscap==1 and isupper(s[0])) return 1;
        return iscap==0;
    }
};