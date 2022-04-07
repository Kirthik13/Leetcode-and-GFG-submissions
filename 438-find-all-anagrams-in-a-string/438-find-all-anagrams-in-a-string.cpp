class Solution {
public:
    bool check(unordered_map<char,int>&m1,unordered_map<char,int>&m2)
    {
        if(m1==m2) return 1;
        return 0;
    }
    vector<int> findAnagrams(string s2, string s1) {
         if(s2.size()<s1.size()) return {};
        
        unordered_map<char,int>m1;
            unordered_map<char,int>m2;
        
        for(auto &i:s1)
        {
            m1[i]++;
        }
        
     
        int win=s1.size();
//         for(int i=0;i<win;i++)
//         {
//             m2[s2[i]]++;
//         }
        
//         if(check(m1,m2)) return 1;
        vector<int>v;
        for(int i=0;i<s2.size();i++)
        {
            if(i>=win){
                if(m2[s2[i-win]]==1) 
                {
                    m2.erase(s2[i-win]);
                }
                else{
                    m2[s2[i-win]]--;
                }
            }
            m2[s2[i]]++;
            
            if(check(m1,m2))
            {
                v.emplace_back(i-win+1);
                // return 1;
            }
        }
        return v;
    }
};