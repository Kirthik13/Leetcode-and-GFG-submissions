class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& roc, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<cap.size();i++)
        {
            v.push_back({cap[i],roc[i]});
        }
        
        sort(begin(v),end(v),[](auto a,auto b)
             {
                 return a.first-a.second<b.first-b.second;
             });
        int c{};
        for(auto &i:v)
        {
            int req=i.first-i.second;
            if(k>=req)
            {
                k-=req;
                c++;
            }
        }
        return c;
    }
};