class Solution {
public:
    string addBinary(string a, string b) {
        string s;
         int i=a.size()-1,j=b.size()-1,carry{};

    while(i>=0 or j>=0)
    {
        int x=i>=0?a[i--]-48:0;
        int y=j>=0?b[j--]-48:0;

        int sum=x+y+carry;
        char c=(sum%2)+48;
        s.insert(s.begin(),c);
        carry=sum/2;
    }
    if(carry>0)
    {
        s.insert(s.begin(),'1');
    }
        return s;
    }
};