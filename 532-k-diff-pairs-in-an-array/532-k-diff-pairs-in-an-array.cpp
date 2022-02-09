class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        unordered_map<int,int>m;
       
        int c{};
        for(auto  &i:v)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            if((k>0 and m.find(i.first+k)!=m.end()) or (k==0 and m[i.first]>=2))
            {
                c++;
            }
        }
        return c;
        
    }
};