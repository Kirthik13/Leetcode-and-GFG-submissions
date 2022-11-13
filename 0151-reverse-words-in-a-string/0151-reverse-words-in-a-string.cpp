class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s),end(s));
        int n=s.size();
        
        int i{},l{},r{},lastidx{};
        while(i<n)
        {
            while(i<n and s[i]==' ') i++;
            while(i<n and s[i]!=' ')
            {
                s[r]=s[i];
                i++;
                r++;
                lastidx=r;
                
                
            }
            
            reverse(begin(s)+l,begin(s)+r);
            s[r]=' ';
            r++;
            l=r;
            i++;
            
        }
        
        s.resize(lastidx);
        return s;
    }
};