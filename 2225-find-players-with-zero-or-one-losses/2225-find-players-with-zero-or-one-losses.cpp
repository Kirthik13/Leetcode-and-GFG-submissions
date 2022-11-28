class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
         vector<vector<int>>tot(2);
        
        map<int,int>m;    
        set<int>st;
        
        for(auto &i:v)
        {
            
            st.insert(i[0]);
            st.insert(i[1]);
            
            m[i[1]]++;
            
        }
        
        
        for(auto &i:st)
        {
            if(m[i]==1)
            {
                tot[1].push_back(i);
            }
            else 
            {
                if(m[i]==0){
                tot[0].push_back(i);
                }
            }            
            
        }
        return tot;
        
    }
};