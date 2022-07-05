class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        
        int ans=0;
        set<int>st(begin(v),end(v));
        for(auto &i:v)
        {
            int el=i;
            if(st.find(el-1)==st.end())
            {
                int next=el+1;
                while(st.find(next)!=st.end())
                {
                    next++;
                }
                ans=max(ans,next-el);

            }
        }
        return ans;
    }
};