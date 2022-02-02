class Solution {
public:
 
    vector<int> findAnagrams(string s, string p) {
        int m1=s.size();
        int n=p.size();
         if(s.size() < p.size())
           return {};
        if(m1==1 )
        {
            if(p.front()==s[0]){
            return {0};
                }
            else{
                return {};
            }
        }
        
        vector<int>ans;
        vector<int>h1(26);
               vector<int>h2(26);
        for(int i=0;i<n;i++)
        {
            h1[s[i]-'a']++;
            h2[p[i]-'a']++;
        }
        if(h1==h2)
        {
            ans.push_back(0);
        }
        for(int i=p.size();i<s.size();i++)
        {
            h1[s[i]-'a']++;
            h1[s[i-p.size()]-'a']--;
           
            if(h1==h2)
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};