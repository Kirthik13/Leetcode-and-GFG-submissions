class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int ch=int(s[i])-'0';
            
            if(ch%2!=0)
            {
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};