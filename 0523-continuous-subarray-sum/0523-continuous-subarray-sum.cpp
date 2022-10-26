class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        map<int,int>m;
        m[0]=-1;
        int runsum{};
        for(int i=0;i<v.size();i++)
        {
            runsum+=v[i];
            
            if(k!=0)
            {
                runsum%=k;
                
            }
            
            if(m.find(runsum)!=m.end())
            {
                if(i-m[runsum]>1) return 1;
            }
            else{
                m[runsum]=i;
            }
        }
        
        return 0;
    }
};