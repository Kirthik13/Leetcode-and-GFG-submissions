class Solution {
public:
    int myAtoi(string s) {
        long long res{};
     int i=s.find_first_not_of(' ');
        if(i>=s.size())
        {
            return 0;
        }
        
        int c=(s[i]=='-')?-1:1;
        if(s[i]=='-' or s[i]=='+')
        {
            i++;
        }
        while(i<s.size() and isdigit(s[i]))
        {
            res=res*10+(s[i]-48);
            if(res*c>=INT_MAX) return INT_MAX;
                if(res*c<=INT_MIN) return INT_MIN;
            // if(res)
            i++;
        }
        return c*res;
    }
};