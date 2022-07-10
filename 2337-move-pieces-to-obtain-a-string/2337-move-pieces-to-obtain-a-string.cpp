class Solution {
public:
    bool canChange(string s, string t) {
        
        int i{},j{};
        int n=s.size();
        while(i<n and j<n)
        {
            while(i<n and s[i]=='_') i++;
            while(j<n and t[j]=='_') j++;
            
            if(i==n and j==n) return 1;
            
            if(s[i]!=t[j]) return 0;
            
            if(s[i]=='L')
            {
                if(i<j) return 0;
            }
            if(s[i]=='R')
            {
                if(i>j) return 0;
            }
            i++;
            j++;

        }
        return 1;
        
    }
};