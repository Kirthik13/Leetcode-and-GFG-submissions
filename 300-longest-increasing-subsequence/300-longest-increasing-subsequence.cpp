class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int>res;
        
        for(int i=0;i<v.size();i++)
        {
            auto idx=lower_bound(begin(res),end(res),v[i])-begin(res);
            if(idx==res.size())
            {
                res.push_back(v[i]);
            }
            else{
                res[idx]=v[i];
            }
        }
        
        return res.size();
    }
};