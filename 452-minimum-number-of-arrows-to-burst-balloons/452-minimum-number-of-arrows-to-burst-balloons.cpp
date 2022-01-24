class Solution {
public:
 int findMinArrowShots(vector<vector<int>>& p) {
  
    if (p.size() <= 1)
      return p.size();
    
   
    sort(p.begin(), p.end());
    
     int en=p[0][1];
     int c=1;
     for(auto i:p)
     {
         int st=i[0];
         en=min(en,i[1]);
         if(st<=en) continue;
         c++;
         en=i[1];
         // en=min(i[1];
     }


	
    return c;
  }

};