class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s==p) return {0};
        if(s.size()<p.size()) return {};
        map<char,int>m1;
        map<char,int>m2;
        vector<int>totans;
        for(auto &i:p) m1[i]++;
        
        for(int i=0;i<p.size();i++)
        {
            m2[s[i]]++;
        }
        if(m1==m2) totans.push_back(0);
        
        for(int i=p.size();i<s.size();i++)
        {
           
            if( m2[s[i-p.size()]]==1)
            {
                m2.erase(s[i-p.size()]);
            }
            else{
                m2[s[i-p.size()]]--;
            }
            m2[s[i]]++;
            
            if(m1==m2) totans.push_back(i-p.size()+1);
            
        }
        
        return totans;
    }
};