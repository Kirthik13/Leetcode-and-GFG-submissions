class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int tot{},sum{};
        for(auto &i:v)
        {
            tot+=i;
        }
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(sum*2==tot-v[i])
            {
                return i;
            }
            sum+=v[i];
        }
        return -1;
    }
};