class Solution {
public:
    set<vector<int>>totans;
    
    void fn(vector<int>& v,int idx,int n)
    {
        if(idx>=n)
        {
            totans.insert(v);
            return;
        }
        
        for(int i=idx;i<n;i++)
        {
            // if(i==idx) continue;
            swap(v[idx],v[i]);
            fn(v,idx+1,n);
            swap(v[idx],v[i]);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& v) {
        int n=v.size();
        fn(v,0,n);
        vector<vector<int>>temp(begin(totans),end(totans));
        
        return temp;
    }
};