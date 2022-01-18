class Solution {
public:
    bool isCovered(vector<vector<int>>& v, int l, int r) {
        int pre[52]={0};
        
        for(auto &i:v)
        {
            // if(l>i[1] or r<i[0] )
            // {
            //     continue;
            // }
            ++pre[i[0]];
            --pre[i[1]+1];
        
        }
        int overlap{};
        for(int i=1;i<=r;i++)
        {
            overlap+=pre[i];
            
            if(i>=l and overlap==0)
            {
                return 0;
            }
        }
        return 1;
        
    }
};