class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
//         int r1=0,c1=0,r2=n-1,c2=n-1;
//         vector<vector<int>>v(n,vector<int>(n));
//         int val=0;
//         while(r1<=r2 and c1<=c2)
//         {
//             for(int i=c1;i<=c2;i++)
//             {
//                 v[r1][i]=++val;
//             }
            
//             for(int i=r1+1;i<=r2;i++)
//             {
//                 v[i][c2]=++val;
//             }
            
//             // if(r1<=r2 and c1<=c2)
//             // {
//                 for(int i=c2-1;i>c1;i--)
//                 {
//                     v[r2][i]=++val;
//                 }
//                 for(int i=r2;i>r1;i--)
//                 {
//                     v[i][c1]=++val;
//                 }
//             // }
            
//             r1++;
//             r2--;
//             c1++;
//             c2--;
            
//         }
//         return v;
         // int m=v.size(),n=v[0].size();
        int left=0,right=n-1,top=0,bot=n-1,val=0;
        vector<vector<int>>v(n,vector<int>(n));
        while(left<=right and top<=bot)
        {
            for(int i=left;i<=right;i++)
            {
               v[top][i]=++val;
            }
            top++;
            
            for(int i=top;i<=bot;i++)
            {
                v[i][right]=++val;
            }
            right--;
                        if(left>right or top>bot) break;

            for(int i=right;i>=left;i--)
            {
               v[bot][i]=++val;
            }
            bot--;
            for(int i=bot;i>=top;i--)
            {
                 v[i][left]=++val;
            }
            left++;
        }
        return v;
    }
};