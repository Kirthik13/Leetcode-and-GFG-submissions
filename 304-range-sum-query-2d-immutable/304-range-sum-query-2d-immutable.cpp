class NumMatrix {
public:
    vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        v.resize(m+1,vector<int>(n+1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i+1][j+1]=matrix[i][j];
                v[i+1][j+1]+=(v[i][j+1]+v[i+1][j]-v[i][j]);
            }
        }
       
//         for(auto &i:v)
//         {
//             for(auto &j:  i)
//             {
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return v[row2+1][col2+1]-v[row1][col2+1]-v[row2+1][col1]+v[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */