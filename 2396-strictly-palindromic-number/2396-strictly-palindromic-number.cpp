class Solution {
public:
    int isvalid(string &s)
    {
        int l=0,r=s.size()-1;
        
        while(l<r)
        {
            if(s[l++]!=s[r--]) return 0;
        }
        return 1;
    }
    
    int fn(int num,int b)
    {
        string s;
        int temp=num;
        // cout<<num<<" ";
        while(num)
        {
            if(num%b==0)
            {
                s.push_back('0');
            }
            else{
                s.push_back('1');
                
            }
            num/=b;
        }
        
        // cout<<s<<endl;
        int eq=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                eq+=pow(b,i);
            }
        }
        
        if(eq==temp) return 0;
        if(isvalid(s)) return 1;
        return 0;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++)
        {
            if(!fn(n,i)) return 0;
        }
        return 1;
    }
};