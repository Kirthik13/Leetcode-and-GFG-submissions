#define all(x) x.begin(),x.end()
class Solution {
public:
    string largestNumber(vector<int>& v) {
        sort(all(v),[](auto a1,auto b)
{
     string s1=to_string(a1);
    string s2=to_string(b);
        return s1+s2>s2+s1;

});
        string res;
        for(auto &i:v)
        {
            res+=to_string(i);
        }
        // res.unique(all(res));
        set<char>st(all(res));
        char c=*st.begin();
        if(st.size()==1 and c=='0')
        {
            cout<<"Asd";
            res=c;
        }
        return res;
    }
};