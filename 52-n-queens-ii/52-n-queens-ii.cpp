class Solution {
public:
    bool isvalid(int row,int col,vector<int>&v)
    {
        for(int i=0;i<row;i++)
        {
            int prow=i;
            int pcol=v[i];
            
            if(pcol==col or abs(pcol-col)==abs(prow-row)) return 0;
        }
        return 1;
        
    }
    int fn(int row,vector<int>&v)
    {
        if(row>=v.size()) return 1;
        
        int ans{};
        for(int col=0;col<v.size();col++)
        {
            if(isvalid(row,col,v))
            {
                v[row]=col;
                ans+=fn(row+1,v);
                v[row]=-1;
                
                
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<int>v(n,-1);
        
        return fn(0,v);
    }
};