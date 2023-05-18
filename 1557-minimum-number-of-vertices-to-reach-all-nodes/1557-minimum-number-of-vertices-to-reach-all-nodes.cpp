class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& ed) {
        vector<vector<int>>v(n);
        for(auto &i:ed)
        {
            v[i[1]].push_back(i[0]);
        }
        
        vector<int>cnt;
        int nos=0;
        for(auto &i:v)
        {
            if(i.size()==0) 
            {
                cnt.push_back(nos);
                // cnt++;
            }
            nos++;
        }
        return cnt;
    
    }
};