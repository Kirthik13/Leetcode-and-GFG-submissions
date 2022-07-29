class Solution {
public:
    string f(string s)
    {
        unordered_map<char,int>m;
        for(auto &i:s)
        {
            if(m.count(i)==0)
            {
                m[i]=m.size();
            }
        }
        
        for(int i=0;i<s.size();i++)
        {
            s[i]='a'+m[s[i]];
        }
        return s;
    }
    vector<string> findAndReplacePattern(vector<string>& v, string p)
    {
         vector<string>totans;
         string fp=f(p);
         for(auto &w:v)
         {
             if(f(w)==fp)
             {
                 totans.push_back(w);
             }
         }
         return totans;
        
        
    }
};