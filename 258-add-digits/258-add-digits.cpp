class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()!=1)
        {
            int ans=0;
            for(int i=0;i<s.size();i++)
            {
                ans+=(char(s[i])-48);
            }
            s=to_string(ans);
        }
        return stoi(s);
    }
};