class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        
        int ans=1;
        unordered_set<int>st(begin(v),end(v));
        for(auto &i:v)
        {
            if(st.find(i)==st.end()) continue;
            st.erase(i);
            
            int prev=i-1,next=i+1;
            
            while(st.find(prev)!=st.end())
            {
                st.erase(prev);
                --prev;
            }
            while(st.find(next)!=st.end())
            {
                st.erase(next);
                ++next;
            }
            
            ans=max(ans,next-prev-1);
        }
        return ans;
    }
};