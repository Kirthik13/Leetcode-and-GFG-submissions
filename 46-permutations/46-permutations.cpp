class Solution {
public:
    vector<vector<int>>totans;
    
    void fn(vector<int>& v,int l,int r)
    {
        if(l==r)
        {
            // totans.insert(v);
            totans.push_back(v);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            swap(v[l],v[i]);
            fn(v,l+1,r);
            swap(v[l],v[i]);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& v) {
        int n=v.size();
        fn(v,0,n-1);
        // vector<vector<int>>temp(begin(totans),end(totans));
        return totans;
        // return temp;
    }
};