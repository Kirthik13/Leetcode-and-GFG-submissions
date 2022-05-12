class Solution {
public:
   
//     void fn(vector<int>& v,int i)
//     {
        
//     }
    vector<vector<int>> permuteUnique(vector<int>& v) {
        set<vector<int>>ans;
       vector<int>tem=v;
        do{
            ans.insert(v);
        }while(prev_permutation(begin(v),end(v)));
        v=tem;
        do{
            ans.insert(v);
        }while(next_permutation(begin(v),end(v)));
        
        vector<vector<int>>tot(begin(ans),end(ans));
        
        
        
        return tot;
    }
};