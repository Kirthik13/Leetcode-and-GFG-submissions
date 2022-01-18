class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v) {
        unordered_map<int,int>m;
        
        int n=v.size();
        int c{};
        for(int i=0;i<n;i++)
        {
            int a=v[i]%60;
            if(a==0)
            {
                c+=m[0];
            }
            else if(m.find(60-a)!=m.end())
            {
                c+=m[60-a];
            }
            m[a]++;
            
            
                
        }
        return c;
    }
};