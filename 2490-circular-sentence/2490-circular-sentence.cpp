class Solution {
public:
    bool isCircularSentence(string s) {
        
        if(s[0]!=s.back()) return 0;
        
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' and i+1<s.size() and s[i-1]!=s[i+1]) return 0;
        }
        return 1;
    }
};