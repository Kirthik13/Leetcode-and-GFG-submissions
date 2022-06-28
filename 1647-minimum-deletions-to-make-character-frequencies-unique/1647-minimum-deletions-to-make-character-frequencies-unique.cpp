class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int>m;
        for(auto &i:s)
        {
            m[i]++;
        }
        unordered_set<int>st;
        int ans{};
        for(auto &i:m)
        {
            int cnt=i.second;
            while(st.find(cnt)!=st.end())
            {
                cnt--;
                ans++;
            }
           
            if(cnt>0) st.insert(cnt);
        }
        return ans;
        
    }
};