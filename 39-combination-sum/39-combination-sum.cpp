class Solution {
public:
    set<vector<int>>st;
    void fn(vector<int>& v, int idx,int n,int target,vector<int>& temp,int sum)
    {
        if(idx>=n)
        {
            if(sum==target)
            {
                
                st.insert(temp);
            }
            return;
        }
        
        if(sum+v[idx]<=target){
            temp.push_back(v[idx]);
            fn(v,idx,n,target,temp,sum+v[idx]);
            if(temp.size()>0) temp.pop_back();
        }
        fn(v,idx+1,n,target,temp,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        int n=v.size();
        sort(begin(v),end(v));
        vector<int> temp;
        fn(v,0,n,target,temp,0);
        vector<vector<int>>curr(begin(st),end(st));
        
        return curr;
    }
};