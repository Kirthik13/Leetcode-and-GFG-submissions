class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int c{};
        unordered_map<int,int>m;
        m[0]=-1;
        int sum{};
        for(int i=0;i<v.size();i++)
        {
           sum+=v[i]?1:-1;
            if(m.find(sum)!=m.end())
            {
                
                c=max(i-m[sum],c);
            }
            else{
            m[sum]=i;
            }
        }
        return c;
    }
};