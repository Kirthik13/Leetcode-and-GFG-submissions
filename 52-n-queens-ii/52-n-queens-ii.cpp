class Solution {
public:
    bool isvalid(vector<vector<char>>&v,int row,int col,int n)
    {
        int j;
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
        {
            if(v[i][j]=='Q' ) return 0;
        }
        for(int i=row+1,j=col-1;i<n and j>=0;i++,j--)
        {
            if(v[i][j]=='Q' ) return 0;
        }
        for(int j=col-1;j>=0;j--)
        {
            if(v[row][j]=='Q' ) return 0;

        }
        return 1;
        
    }
    int fn( vector<vector<char>>&v,int col,int n,int &ans)
    {
        if(col==n)
        {
         
            // for(auto &i:v)
            //     {
            //         for(auto &j:i)
            //         {
            //             cout<<j<<" ";
            //         }
            //         cout<<endl;
            //     }
            // ans++;
            return 1;
        }
        int g=0;
        for(int row=0;row<n;row++)
        {
           
            if(isvalid(v,row,col,n) and v[row][col]=='.')
            {
                v[row][col]='Q';
                
                g+=fn(v,col+1,n,ans);
                v[row][col]='.';
            }
        }
        return g;
        
    }
    int totalNQueens(int n) {
        vector<vector<char>>v(n,vector<char>(n,'.'));
         
        int ans{};
        return fn(v,0,n,ans);
        // return ans;
    }
};