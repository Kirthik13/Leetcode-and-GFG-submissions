class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        map<int,vector<int>>m;
        for(auto &i:v)
        {
            m[i[0]].push_back(i[1]);
        }
        vector<int>ans(n+1,0);
        for(auto &i:m)
        {
            for(auto &j:i.second)
            {
                ans[j]++;
            }
        }
        for(auto i=1;i<ans.size();i++)
        {
            if(ans[i]==n-1 and m.find(i)==m.end()) return i;
        }
        return -1;
    }
};