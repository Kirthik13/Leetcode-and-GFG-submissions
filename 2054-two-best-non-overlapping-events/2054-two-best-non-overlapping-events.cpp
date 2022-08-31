class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        vector<vector<int>>temp;
        
        for(auto &i:v)
        {
            temp.push_back({i[0],1,i[2]});
            temp.push_back({i[1]+1,0,i[2]});
            
        }
        
        sort(begin(temp),end(temp));
        
        int m=0,ans{};
        for(auto &i:temp)
        {
            if(i[1])
            {
                ans=max(ans,m+i[2]);
            }
            else{
                m=max(m,i[2]);
            }
        }
        return ans;
    }
};