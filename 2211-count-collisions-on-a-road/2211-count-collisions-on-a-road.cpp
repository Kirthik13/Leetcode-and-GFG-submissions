class Solution {
public:
    int countCollisions(string s) {
        int c{};
        int n=s.size(),i=0;
        int carfromright{};
        while(i<n and s[i]=='L') i++;
        for(;i<n;i++)
        {
            if(s[i]=='R') ++carfromright;
            else{
                c+=(s[i]=='S')?carfromright:carfromright+1;
                carfromright=0;
            }
        }
        return c;
        
    }
};