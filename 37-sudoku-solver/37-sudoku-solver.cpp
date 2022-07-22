class Solution {
public:
    bool isvalid(vector<vector<char>>& v,int r,int c,int nos)
    {
        char num=char(nos)+48;
        for(int i=0;i<9;i++)
        {
            if(v[r][i]==num) return 0;
        }
        
         for(int i=0;i<9;i++)
        {
            if(v[i][c]==num) return 0;
        }
        
        int st,en;
        if(r>=0 and r<=2) st=0;
        if(r>=3 and r<=5) st=3;
        if(r>=6 and r<=8) st=6;
        
        if(c>=0 and c<=2) en=0;
        if(c>=3 and c<=5) en=3;
        if(c>=6 and c<=8) en=6;
        
        for(int i=st;i<=st+2;i++)
        {
            for(int j=en;j<=en+2;j++)
            {
                if(v[i][j]==num) return 0;
            }

            
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