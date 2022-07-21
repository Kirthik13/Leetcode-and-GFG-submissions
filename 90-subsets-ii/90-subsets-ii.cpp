class Solution {
public:
    set<vector<int>>totans;
    void fn(vector<int>& v,int idx,int n,vector<int>& temp)
    {
        if(idx>=n)
            
        {
            vector<int>v3=temp;
            sort(begin(temp),end(temp));
            totans.insert(temp);
            temp=v3;
                
            return ;
        }
        
        fn(v,idx+1,n,temp);
        temp.push_back(v[idx]);
        fn(v,idx+1,n,temp);
        if(temp.size()>0) temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v)
    {
        int n=v.size();
        vector<int> temp;
        fn(v,0,n,temp);
        
        
        vector<vector<int>>curr(begin(totans),end(totans));
        
        return curr;
    }
};