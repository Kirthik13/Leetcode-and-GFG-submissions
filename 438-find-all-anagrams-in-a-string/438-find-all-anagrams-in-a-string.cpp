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
        unordered_map<char,int>m;
        for(auto &i:p)
        {
            m[i]--;
        }
        for(int i=0;i<p.size();i++)
        {
            m[s[i]]++;
            if(m[s[i]]==0) m.erase(s[i]);
        }
        if(m.size()==0)
        {
            ans.push_back(0);
        }
        for(int i=p.size(),j=0;i<s.size() and j<s.size();i++,j++)
        {
            m[s[i]]++;
            m[s[j]]--;
            if(m[s[i]]==0) m.erase(s[i]);
            if(m[s[j]]==0) m.erase(s[j]);
            if(m.size()==0) ans.push_back(j+1);

        }
        return ans;
    }
};