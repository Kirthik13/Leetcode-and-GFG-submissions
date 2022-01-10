class Solution {
public:
    bool isRobotBounded(string s) {
//          char curr='N';
//     int x{},y{};
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='G')
//         {
//             y+=curr=='N'?1:0;
//             y+=curr=='S'?-1:0;
//             x+=curr=='E'?1:0;
//             x+=curr=='W'?-1:0;

//         }
//         else{
//             char incom=s[i];

//           if(curr=='N')
//             {
//                 curr=incom=='L'?'W':'E';
//             }
//             else if(curr=='S')
//             {
//                 curr=incom=='L'?'E':'W';

//             }
//           else  if(curr=='E')
//             {
//                 curr=incom=='L'?'N':'S';

//             }
//            else if(curr=='W')
//             {
//                 // curr=incom=='L'?'E':'W';
//                 curr=incom=='L'?'S':'N';

//             }
//         }
//     }
//         return (x==0 and y==0) or curr!='N';
        
        
         vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int x{},y{},j{};
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='G')
        {
            x+=dir[j][0];
            y+=dir[j][1];
        }
        else if(s[i]=='L'){
            j--;
        j=(j+4)%4;
        }   
        else {
            j=(j+1)%4;
        }   
    }

    return ((x==0 and y==0 ) or (j!=0));
    }
};