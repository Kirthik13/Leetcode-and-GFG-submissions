class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
     
        int maxsf{},maxsum{};
        for(int i=0;i<v.size();i++)
        {
            maxsum+=v[i];
            
            maxsf=max(maxsum,maxsf);
            
            if(maxsum<0)
            {
                maxsum=0;
            }
        }
        
                int minsf{},minsum{};

         for(int i=0;i<v.size();i++)
        {
            minsum+=v[i];
            
            minsf=min(minsum,minsf);
            
            if(minsum>0)
            {
                minsum=0;
            }
        }
        
        // return maxsf-minsf;
	return max(abs(maxsf), abs(minsf));        
    
    }
};