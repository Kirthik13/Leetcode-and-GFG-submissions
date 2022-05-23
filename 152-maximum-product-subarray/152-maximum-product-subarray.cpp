class Solution {
public:
    int maxProduct(vector<int>& v) {
        vector<int>ans2(begin(v),end(v));
        
        
        reverse(begin(ans2),end(ans2));
        
        
            
         for(int i=1;i<v.size();i++){

             if(v[i-1]!=0){
                v[i]*=v[i-1];
             }
               if(ans2[i-1]!=0){
                 ans2[i]*=ans2[i-1];
             }
        }
        return max(*max_element(begin(v),end(v)),*max_element(begin(ans2),end(ans2)));
    }
};