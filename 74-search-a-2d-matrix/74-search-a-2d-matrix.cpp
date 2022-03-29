class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
//         int n=v[0].size(),m=v.size();
//         int l=0,r=(n*m)-1;
        
//         while(l<=r)
//         {
//             int mid=(l+r)/2;
            
//             if(v[mid/n][mid%n]==target) return 1;
            
//             if(v[mid/n][mid%n]<target) l=mid+1;
//             else{
//                 r=mid-1;
//             }
                
//         }
//         return 0;
        
        
        int l=0,h=v.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(v[mid][0]==target) return 1;
            
            if(v[mid][0]<target) l=mid+1;
            else h=mid-1;
        }
        int row=h;
        
        if(row>=0)
        {
            l=0;
            h=v[0].size()-1;
            
            while(l<=h)
            {
                int mid=(l+h)/2;

                if(v[row][mid]==target) return 1;

                if(v[row][mid]<target) l=mid+1;
                else h=mid-1;
            }
           
        }
        return 0;
    }
};