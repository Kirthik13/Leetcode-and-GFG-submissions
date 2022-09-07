class Solution {
public:
    int maxPower(string s) {
        int cnt=1;
        
        char ch=s[0];
        int st=0;
        for(int i=1;i<=s.size();i++)
        {
            if(ch!=s[i] or i==s.size())
            {
                cnt=max(cnt,i-st);
                st=i;
                ch=s[i];
            }
        }
        return cnt;
    }
};