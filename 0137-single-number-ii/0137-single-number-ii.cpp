class Solution {
public:
    int singleNumber(vector<int>& v) {
        map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            if(i.second==1) return i.first;
        }
        return 0;
    }
};