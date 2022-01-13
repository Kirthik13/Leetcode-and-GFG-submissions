class Solution {
public:
    int numPairsDivisibleBy60(vector<int>&v) {
        unordered_map<int,int>m;
        int n=v.size(),c{};
        // for(int i=0;i<n;i++)
        // {
        //     int a=v[i]%60;
        //     if(a==0)
        //     {
        //         c+=m[0];
        //     }
        //     else{
        //         c+=m[60-a];
        //     }
        //     m[a]++;
        // }
        
        for(auto i:v)
        {
            m[i%60]++;
        }
        c+=(m[0]*(m[0]-1))/2;
            c+=(m[30]*(m[30]-1))/2;
    for(int i=1;i<=29;i++)
    {
        c+=m[i]*m[60-i];
    }
        return c;
    }
};