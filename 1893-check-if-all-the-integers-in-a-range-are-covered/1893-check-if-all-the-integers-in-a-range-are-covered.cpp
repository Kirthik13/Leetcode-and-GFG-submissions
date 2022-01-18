class Solution {
public:
    bool isCovered(vector<vector<int>>& v, int l, int r) {
        // vector<vector<int>>v={{1,10},{10,20}};
unordered_map<int,int>m;
 // int l= 21;
 // int r=21;
 for(int i=l;i<=r;i++)
 {
     m[i]++;
 }

int num=l;
 for(auto &i:v)
 {
   int l1=i[0];
   int r1=i[1];

   for(int j=l1;j<=r1;j++)
   {
       if(m.find(j)!=m.end())
       {
           m[j]++;
       }
   }
 }

 for(int i=l;i<=r;i++)
 {
     if(m[i]==1)
     {
 // cout<<"fasle";
         return 0;
         // break;
     }
 }
 // cout<<"true";
 return true;
    }
};