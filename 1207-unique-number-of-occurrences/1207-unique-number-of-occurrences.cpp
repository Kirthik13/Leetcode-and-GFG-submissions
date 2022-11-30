class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
//         map<int,int>m;
//         for(auto &i:v)
//         {
//             m[i]++;
//         }
//         unordered_set<int>st;
//         for(auto &i:m)
//         {
//             if(st.find(i.second)!=st.end()) return 0;
//             st.insert(i.second);
//         }
        
//         return 1;
        
        
        vector<int>v2(2001);
        
        for(auto &i:v)
        {
            v2[i+1000]++;
        }
        sort(begin(v2),end(v2));
        for(int i=1;i<=2000;i++)
        {
            if(v2[i] and v2[i]==v2[i-1]) return 0;
        }
        return 1;
    }
};