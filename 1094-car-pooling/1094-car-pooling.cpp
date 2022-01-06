class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

 vector<int>res;
 for(int i=0;i<trips.size();i++){
    
 // res.insert(res.end(),trips[i][2]);
     res.emplace_back(trips[i][2]);
   
 }
 
int max=*max_element(res.begin(),res.end());

vector<int>r(max+1,0);

for(int i=0;i<trips.size();i++){
   

        r[trips[i][2]]-=trips[i][0];
    r[trips[i][1]]+=trips[i][0];

    

}


 int current=0;



    
   
    


for(int i=0;i<r.size();i++){
    if(current<=capacity){
current+=r[i];
    }
    else{
        
        return false;
    }
}

return true;
        
    }
};