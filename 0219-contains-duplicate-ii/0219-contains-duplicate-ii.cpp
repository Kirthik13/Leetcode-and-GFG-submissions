class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k1) {
       map<int,vector<int>>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]].push_back(i);
        }
        
        for(auto &i:m)
        {
            int pi=0,pj=i.second.size();
            // while(pi<pj)
            // {
            //     if(abs(i.second[pi]-i.second[pj])<=k)
            //     {
            //         return 1;
            //     }
            //     else{
            //         pj--;
            //     }
            // }
            
            for(int j=0;j<pj;j++)
            {
                for(int k=j+1;k<pj;k++)
                {
                    if(abs(i.second[j]-i.second[k])<=k1)
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};