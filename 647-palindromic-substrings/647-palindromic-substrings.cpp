class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==1) return 1;
        int m{};
        for(int i=0;i<s.size();i++)
        {
            int l=i,r=i;
            while(l>=0 and r<s.size() and s[l]==s[r])
            {
                m++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 and r<s.size() and s[l]==s[r])
            {
                m++;
                l--;
                r++;
            }
            
        }
        return m;
    }
};