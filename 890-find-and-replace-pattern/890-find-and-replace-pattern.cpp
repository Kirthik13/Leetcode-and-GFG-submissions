class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& v, string p)
    {
         vector<string>totans;
         map<char,int>m;
         map<char,int>m2;
         for(int i=0;i<v.size();i++)
         {
             string s=v[i];
             if(s.size()==p.size())
             {
                 
                 
                 int fl=1;
                 for(int j=0;j<s.size();j++)
                 {
                     if((m.find(p[j])!=m.end() and m[p[j]]!=s[j]) or (m2.find(s[j])!=m2.end() and m2[s[j]]!=p[j]))
                     {
                         fl=0;
                         break;
                     }
                         
                     m[p[j]]=s[j];
                     m2[s[j]]=p[j];
                 }
                 
                 if(fl)
                 {
                     totans.push_back(s);
                 }
                 m.clear();
                 m2.clear();
                 
             }
         }
        return totans;
        
        
    }
};