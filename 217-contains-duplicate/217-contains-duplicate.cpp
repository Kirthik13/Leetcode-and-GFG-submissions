class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        // unordered_map<int,int>m;
        // for(auto &i:v)
        // {
        //     m[i]++;
        //     if(m[i]>=2) return 1;
        // }
        // return 0;
        
        sort(begin(v),end(v));
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]==v[i]) return 1;
        }
        return 0;
    }
};