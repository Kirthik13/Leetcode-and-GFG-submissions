class Solution {
public:
    bool detectCapitalUse(string s){
        int caps{};
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(int(s[i])>=65 and int(s[i])<97)
            {
                ++caps;
            }
        }
        if(caps==n)
        {
            return 1;
        }
        if(caps==1)
        {
            return (int(s[0])>=65 and int(s[0])<97)?1:0;
        }
        if(caps==0)
        {
            return 1;
        }
        return 0;
    }
};