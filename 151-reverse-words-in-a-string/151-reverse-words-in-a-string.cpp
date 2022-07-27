class Solution {
public:
    string reverseWords(string s) {
      reverse(s.begin(), s.end());
        int i{},j{},n=s.size(),stidx{},lastidx{};
        while(j<n)
        {
            while(j<n and s[j]==' ') j++;
            
            int stidx=i;
            
            while(j<n and s[j]!=' ')
            {
                s[i++]=s[j++];
                lastidx=i;

            }
            
            reverse(s.begin()+stidx,s.begin()+lastidx);
            s[i++]=' ';
            
        }
        s.resize(lastidx);
        return s;
    }
};