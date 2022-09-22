class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        
        vector<int>res;
        // set<int>eveset;
        int sum{};
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%2==0) 
            {
                // eveset.insert(i);
                sum+=v[i];
            }
        }
        
         for (auto &q : q)
         {
            if (v[q[1]] % 2 == 0) sum -= v[q[1]];
            v[q[1]] += q[0];
            if (v[q[1]] % 2 == 0) sum += v[q[1]];
            res.push_back(sum);
         }
        
        return res;
       
    }
};