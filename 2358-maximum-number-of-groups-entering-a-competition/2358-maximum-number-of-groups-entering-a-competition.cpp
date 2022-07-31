class Solution {
public:
    int maximumGroups(vector<int>& v) {
        int n=v.size();

        int ans{};
        int curr_grpsum{};
        int curr_grp{};
        int p{},total_p{};
        sort(begin(v),end(v));
        
        for(auto &el:v)
        {
            curr_grpsum+=el;
            curr_grp++;
            if(curr_grpsum>total_p and curr_grp>p)
            {
                total_p=curr_grpsum;
                p=curr_grp;
                curr_grpsum=0;
                curr_grp=0;
                ans++;
            }
        }
        return ans;
      
    }
};