class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>>hash;
        for(int i=0;i<t.size();i++)
        {
            hash[t[i]].emplace_back(i);
        }
        int pre=-1;
        
        for(auto i:s)
        {
            auto it=hash.find(i);
            if(it==hash.end()) return false;
            auto vec=it->second;
            auto pos=upper_bound(begin(vec),end(vec),pre);
            if(pos==vec.end()) return false;
            pre=*pos;
            
        }
        return true;
    }
};