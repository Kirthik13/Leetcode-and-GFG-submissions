class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
                int g;
            bitset<32> bs(i);
                    g=bs.count();
            
            ans.push_back(g);
        }
        return ans;
    }
};