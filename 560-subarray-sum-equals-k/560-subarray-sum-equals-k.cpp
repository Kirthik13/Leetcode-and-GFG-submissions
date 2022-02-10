class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        if(v.size()==1)
        {
            return (v[0]==k)?1:0;
        }
   
        unordered_map<int,int>m;
        int c{},sum{};
        for(auto &i:v)
        {
            sum+=i;
            if(sum==k)
             
            {
                c+=1;
            }
             // if(m.find(sum-k)!=m.end()) {
                c+=m[sum-k];
            // }
            m[sum]++;    
        }
        
        return c;
    }
};