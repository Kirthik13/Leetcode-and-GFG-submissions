
class Solution {
public:
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
    vector<vector<string>>tot;
    void fn(int idx,string &s,vector<string>&ans)
    {
        if(idx==s.size())
        {
            tot.push_back(ans);
            return;
        }
        int c=1;
        for(int i=idx;i<s.size();i++)
        {
            string k=s.substr(idx,c);
            if(ispalin(k))
            {
                ans.push_back(k);
                fn(i+1,s,ans);
                ans.pop_back();
                
            }
            c++;
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>ans;
        fn(0,s,ans);
        return tot;
    }
};