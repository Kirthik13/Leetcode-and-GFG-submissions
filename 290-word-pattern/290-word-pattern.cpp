class Solution {
public:
    bool wordPattern(string pat, string s) {
        stringstream st(s);
string sam;
vector<string>v;
while(st>>sam)
{
    v.push_back(sam);
}
if(v.size()!=pat.size())
{
    // cout<<"false";
    return 0;
}
unordered_map<char,string>m;
set<string>s1;
for(int i=0;i<pat.size();i++)
{
    char c=pat[i];
    if(m.find(c)==m.end())
    {
        if(s1.find(v[i])!=s1.end())
        {
            // cout<<"false";
            return 0;
        }
        m[c]=v[i];
        s1.insert(v[i]);
    }
    else{
        if(m[c]!=v[i])
        {
            // cout<<"false";
            return 0;
        }
    }
}
// cout<<"true";
        return 1;
    }
};