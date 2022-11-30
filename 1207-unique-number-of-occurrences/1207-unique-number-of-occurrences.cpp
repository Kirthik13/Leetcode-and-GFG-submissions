class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        unordered_set<int>st;
        for(auto &i:m)
        {
            if(st.find(i.second)!=st.end()) return 0;
            st.insert(i.second);
        }
        
        return 1;
        
    }
};