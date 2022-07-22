class Solution {
public:
    bool isvalid(vector<vector<char>>& v,int r,int c,int nos)
    {
        char num=char(nos)+48;
        for(int i=0;i<9;i++)
        {
            if(v[r][i]==num) return 0;
        
            if(v[i][c]==num) return 0;
        
        
     
            if(v[(3*(r/3))+(i/3)][(3*(c/3))+(i%3)]==num) return 0;
            

            
        }
        
        return 1;
        
        
        
        
    }
    bool fn(vector<vector<char>>& v,int idx,int n,vector<pair<int,int>>&spaces)
    {
        if(idx>=n)
        {
            return 1;
        }
        int r=spaces[idx].first;
        int c=spaces[idx].second;
        
       
                 for(int num=1;num<=9;num++)
                 {
                        if(isvalid(v,r,c,num))
                         { 
                             char ch=char(num)+48;
                            // cout<<"ch : "<<ch<<endl;
                             v[r][c]=ch; 
                             if(fn(v,idx+1,n,spaces)) return 1;
                             v[r][c]='.';
                         }                         

                }
                     
             return 0;
            
            
     
    }
    void solveSudoku(vector<vector<char>>& v) {
        vector<pair<int,int>>spaces;
        for(int i=0;i<9;i++)
        {
             for(int j=0;j<9;j++)
             {
                 if(v[i][j]=='.')
                 {     
                     spaces.push_back({i,j});
                 }
             }
        }
        int n=spaces.size();
        bool g=fn(v,0,n,spaces);
        
        
    }
};