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
            int pos=upper_bound(begin(vec),end(vec),pre)-begin(vec);
            if(pos==vec.size()) return false;
            pre=vec[pos];
            
        }
        return true;
    }
};