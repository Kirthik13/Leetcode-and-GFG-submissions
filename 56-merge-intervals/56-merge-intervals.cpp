class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        if(v.size()==1) return v;
        vector<vector<int>>totans;
        
        sort(begin(v),end(v));
        int st=v[0][0];
        int en=v[0][1];
        for(int i=1;i<=v.size();i++)
        {
            if(i==v.size())
            {
                totans.push_back({st,en});
                continue;
                
            }
            if(en<v[i][0])
            {
                totans.push_back({st,en});
                st=v[i][0];
                en=v[i][1];
            }
            else if(en>=v[i][0]){
                en=max(v[i][1],en);
            }
                
        }
        
        return totans;
    }
};