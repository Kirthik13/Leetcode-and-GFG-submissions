class Solution {
public:
    vector<int> shuffle(vector<int>& v, int n) {
        int i=0;
        int j=n;
        vector<int>tot;
        while(i<n and j<2*n)
        {
            tot.emplace_back(v[i]);
                tot.emplace_back(v[j]);
            i++;
            j++;
        }
        return tot;
    }
};