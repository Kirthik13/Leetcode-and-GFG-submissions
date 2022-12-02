class Solution {
public:
    bool closeStrings(string s1, string s2) {

        vector<int>m1(26);
        vector<int>m2(26);
        set<char>ms1,ms2;
        
        for(auto &i:s1)
        {
            m1[i-'a']++;
            ms1.insert(i);
        }
        for(auto &i:s2)
        {
            m2[i-'a']++;
            ms2.insert(i);
            
            
        }
        
        
        
//         for(auto &i:m1) ms1.insert(i.second);
//         for(auto &i:m2) ms2.insert(i.second);
        
        sort(begin(m1),end(m1));
        sort(begin(m2),end(m2));
        
        return ms1==ms2 and m1==m2;
    }
};