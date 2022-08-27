class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            map<char,int>m;
        int win=0,st=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
            
                st=max(st,m[s[i]]+1);
               
            }
                m[s[i]]=i;
            
            win=max(win,i-st+1);
        }
        return win;
    }
};