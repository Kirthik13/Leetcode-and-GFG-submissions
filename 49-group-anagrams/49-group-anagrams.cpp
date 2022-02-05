class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
         vector<vector<string>>tot;
        unordered_map<string,vector<string>>m;
        // Trie h;
        for(int i=0;i<v.size();i++)
        {
            string k=v[i];
            sort(k.begin(),k.end());
            // h.insert(k);
            m[k].emplace_back(v[i]);
            
            
        }
        for(auto i:m)
        {
           tot.emplace_back(i.second);
        }
        return tot;
    }
};