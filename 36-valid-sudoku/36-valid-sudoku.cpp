class Solution {
public:
    bool rowsfn(vector<vector<char>>& v,int r,int c,int n)
    {
        vector<int>hash(10,0);
        for(int i=0;i<9;i++)
        {
            int g=int(v[i][c])-48;

            if(v[i][c]!='.' )
            {
                if(hash[g]>0) return false;
            }
            if(v[i][c]!='.' )
            {
                hash[g]++;
            }
        }
        return 1;
    }
        
     bool colfn(vector<vector<char>>& v,int r,int c,int n)
    {
        vector<int>hash(10,0);
        for(int i=0;i<9;i++)
        {
                int g=int(v[r][i])-48;
            
            if(v[r][i]!='.' )
            {
                if(hash[g]>0) return false;
            }
            if(v[r][i]!='.' )
            {
                hash[g]++;
            }
        }
         return 1;
    }
    bool indfn(vector<vector<char>>& v,int r,int c,int n)
    {
         vector<int>hash(10,0);
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                int g=int(v[i][j])-48;
                
                if(v[i][j]!='.' )
                {
                    if(hash[g]>0) return false;
                }
                if(v[i][j]!='.' )
                {
                    // int g=int(v[i][j])-48;
                    hash[g]++;
                }
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& v) {
        int n=v.size();
        
        for(int i=0;i<9;i++)
        {
            
            if(!rowsfn(v,0,i,n))
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            
            if(!colfn(v,i,0,n))
            {

                return false;
            }
        }
        
        // vector<pair<int,int>> dir={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        
//         for(auto &i:dir)
//         {
//             if(!indfn(v,i.first,i.second,n))
//             {

//                 return 0;
//             }
//         }
        
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                if(!indfn(v,i,j,n))
                {

                    return 0;
                }
            }
        }
        return 1;
        
        
    }
};