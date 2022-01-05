class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        {
            return 1;
        }
        int k=n;
    string s;
    while(k!=0)
    {
        s.push_back((k%2)+48);
        k/=2;
    }
            reverse(begin(s),end(s));

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
    int g=0;
    int ans=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        ans+=(s[i]=='1')?pow(2,g):0;
        g++;
    }
        return ans;
    }
};