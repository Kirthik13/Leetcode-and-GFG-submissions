class Solution {
public:
    
    void fn(string &s,int l,int r,int &maxlen,int &st)
    {
        while(l>=0 and r<s.size() and s[l]==s[r])
        {
            l--;
            r++;
        }
        
        if(maxlen<r-l-1)
        {
            maxlen=r-l-1;
            st=l+1;
        
            
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=INT_MIN;
        int st;
        if(n==1) return s;
        for(int i=0;i<n-1;i++)
        {
            fn(s,i,i,maxlen,st);
            fn(s,i,i+1,maxlen,st);
        }
        return s.substr(st,maxlen);
    }
};