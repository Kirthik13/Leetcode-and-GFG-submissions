class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) return 0;
        vector<int>m1(26,0),m2(26,0);
       
        for(auto &i:s1)
        {
            m1[i-'a']++;
            // st1.insert(i);
        }
        for(auto &i:s2)
        {
            m2[i-'a']++;
                // st2.insert(i);

        }
        
        if(equal(begin(m1),end(m1),begin(m2),end(m2),[](auto a,auto b)
           {
               return (bool)a==(bool)b;
           }
          )==false)
        {
            return 0;
        }
          sort(begin(m1), end(m1));
    sort(begin(m2), end(m2));
    return m1==m2;
        
    }
};