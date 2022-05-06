class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        unordered_map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
            if(m[i]>=2) return 1;
        }
        return 0;
    }
};