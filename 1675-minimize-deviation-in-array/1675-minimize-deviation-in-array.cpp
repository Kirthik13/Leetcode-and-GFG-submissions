class Solution {
public:
   
    int minimumDeviation(vector<int>& v) {
     set<int>s(begin(v),end(v));
        
        int mindev=*s.rbegin()-*s.begin();
        int val=*s.begin();
        while(val%2==1)
        {
            s.erase(val);
            s.insert(val*2);
            val=*s.begin();
            mindev=min(mindev,*s.rbegin()-val);
        }
        val=*s.rbegin();
        while(val%2==0)
        {
            s.erase(val);
            s.insert(val/2);
            val=*s.rbegin();
            mindev=min(mindev,val-*s.begin());
        }
        return mindev;
    
    }
};