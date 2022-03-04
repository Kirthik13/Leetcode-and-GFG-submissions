class Solution {
public:
    double champagneTower(int n, int row, int col) {
        vector<vector<double>>v(101,vector<double>(101,0.0));
        v[0][0]=n;
        for(int i=0;i<=row;i++)
        {
            for(int j=0;j<=col;j++)
            {
                double rem=max(v[i][j]-1.0,0.0);
                v[i+1][j]+=rem/2.0;
                        v[i+1][j+1]+=rem/2.0;

            }
        }
        
        return min(v[row][col],1.0);
       
    }
};