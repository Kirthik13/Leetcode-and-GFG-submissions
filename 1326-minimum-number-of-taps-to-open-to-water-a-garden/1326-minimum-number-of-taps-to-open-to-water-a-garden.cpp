class Solution {
public:
    
    int minTaps(int n, vector<int>& v) {
       
        int max=0,min{},cnt{};
        
        while(max<n)
        {
            for(int i=0;i<v.size();i++)
            {
                if(i-v[i]<=min and i+v[i]>max)
                {
                    max=i+v[i];
                }
            }
            
            if(min==max) return -1;
            
            min=max;
            cnt++;
        }
        
        return cnt;
    }
};