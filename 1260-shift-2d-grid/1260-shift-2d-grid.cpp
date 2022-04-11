class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& v, int k) {
        deque<int>dq;
        for(auto &i:v)
        {
            for(auto &j:i)
            {
                dq.push_back(j);
            }
        }
        while(k--)
        {
            int g=dq.back();
            dq.pop_back();
            dq.push_front(g);
        }
        
         for(auto &i:v)
        {
            for(auto &j:i)
            {
                j=dq.front();
                dq.pop_front();
            }
        }
       return v;
    }
};