class Solution {
public:
    int fourSumCount(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4) {
        int c{};
        unordered_map<int,int>m;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
               int sum=v1[i]+v2[j];
                
                
                    m[sum]++;
                
            }
        }
     for(int k=0;k<v3.size();k++)
    {
                 for(int z=0;z<v4.size();z++)
                 {
                    int sum=v3[k]+v4[z];
                     sum*=-1;
                     if(m[sum]>0)
                     {
                         c+=m[sum];
                     }
                 }
    }
    
        return c;
    }
};