class Solution {
public:
    vector<vector<string>>tot;
    bool isvalid(vector<string>&v,int row,int col,int n)
    {
        if(v[row][col]!='.') return 0;
        
//         for(int i=row+1;i<n;i++)
//         {
//             if(v[i][col]=='Q') return 0;
//         }
//         for(int i=row-1;i>=0;i--)
//         {
//             if(v[i][col]=='Q') return 0;
//         }
//          for(int i=col+1;i<n;i++)
//         {
//             if(v[row][i]=='Q') return 0;
//         }
//         for(int i=col-1;i>=0;i--)
//         {
//             if(v[row][i]=='Q') return 0;
//         }
//         int j;
//         for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++)
//         {
//             if(v[i][j]=='Q') return 0;
//         }
//         for(int i=row+1,j=col+1;i<n and j<n;i++,j++)
//         {
//             if(v[i][j]=='Q') return 0;
//         }
//         for(int i=row+1,j=col-1;i<n and j>=0;i++,j--)
//         {
//             if(v[i][j]=='Q') return 0;
//         }
//         for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
//         {
//             if(v[i][j]=='Q') return 0;
//         }
//         return 1;
        
         for(int c1=col;c1>=0;c1--){
            if(v[row][c1]=='Q'){
                return false;
            }
        }
          int row1=row;
        int col1=col;
        while(row1>=0 and col1>=0){
             if(v[row1][col1]=='Q'){
                return false;
            }
            row1--;
            col1--;
        }
        row1=row;
        col1=col;
         while(row1<n and col1>=0){
             if(v[row1][col1]=='Q'){
                return false;
            }
            row1++;
            col1--;
        }
        return true;
    }
    void fn( vector<string>&v,int n,int row,int col)
    {
        // if(i<0 or i>=n or j<0 or j>=n) return 0;
        
        if( col>=n)
        {
          
           
            tot.push_back(v);
                
            
            return ;
            
        }
        
        for(int i=0;i<n;i++)
        {
           
                if(isvalid(v,i,col,n) )
                {
                    v[i][col]='Q';
                    fn(v,n,0,col+1);
                    
                        v[i][col]='.';
                    
                    
                }
            
        }
      
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n);
        
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            v[i]=s;
        }
        
        fn(v,n,0,0);
        
        return tot;
    }
};


// class Solution {
// public:
//     bool place(vector<string>v,int row,int col,int n){
//         for(int c1=col;c1>=0;c1--){
//             if(v[row][c1]=='Q'){
//                 return false;
//             }
//         }
//           int row1=row;
//         int col1=col;
//         while(row1>=0 and col1>=0){
//              if(v[row1][col1]=='Q'){
//                 return false;
//             }
//             row1--;
//             col1--;
//         }
//         row1=row;
//         col1=col;
//          while(row1<n and col1>=0){
//              if(v[row1][col1]=='Q'){
//                 return false;
//             }
//             row1++;
//             col1--;
//         }
//         return true;
        
//     }
//     void sub(vector<vector<string>>&res,vector<string>&v,int col,int n){
//         if(col==n){
//             res.push_back(v);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(place(v,row,col,n)){
//                 v[row][col]='Q';
//                  sub(res,v,col+1,n);
//                  v[row][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string>v(n);
//         string str(n,'.');
//         for(int i=0;i<n;i++){
//             v[i]=str;
//         }
//         vector<vector<string>>res;
//         sub(res,v,0,n);
//         return res;
        
//     }
// };