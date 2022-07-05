class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        set<int>st(begin(v),end(v));
        int ans=1,curr_max=1;
        int prev=*st.begin();
        auto i=st.begin();
        i++;
        for(i;i!=st.end();i++)
        {
            int el=*i;
            if(prev+1==el)
            {
             curr_max++;   
            }
            else{
                ans=max(curr_max,ans);
                curr_max=1;
            }
            prev=el;

        }
         ans=max(curr_max,ans);
        return ans;
            
    }
};