bool ispalin(string &s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
class Solution {
public:
    bool isPalindrome(string t) {
        if(t.size()==1) return 1;
        string s;
        for(auto &i:t)
        {
            if(isalpha(i) or isdigit(i))
            {
                s+=i;
            }
        }
        std::transform(begin(s),end(s),begin(s),::tolower);
        // cout<<s;
        return (ispalin(s))?1:0;
        // return 1;
    }
};