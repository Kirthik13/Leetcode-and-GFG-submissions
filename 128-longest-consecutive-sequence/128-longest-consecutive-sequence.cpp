class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        
        int ans=1;
        unordered_set<int>st(begin(v),end(v));
        for(auto &i:v)
        {
            if(st.count(i-1)) continue;
            
            int el=i;
            int j=1;
            while(st.find(el+j)!=st.end())
            {
                j++;
            }
            
            ans=max(ans,(el+j)-el);
            
        }
        return ans;
    }
};