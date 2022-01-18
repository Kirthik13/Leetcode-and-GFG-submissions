class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if(n==0)
        {
            return 1;
        }
        for(int i=0;i<v.size();i++)
    {
        
        if(i==0)
        {
            if(v.size()>1){
            if(v[i]==0 and v[i+1]==0)
            {
                v[i]=1;
                n--;
            }
            }
            else{
                if(v[i]==0)
                {
                    v[i]=1;
                    n--;
                }
            }
        }
        else if(i==v.size()-1)
        {
             if(v.size()>1){
            if(v[i]==0 and v[i-1]==0)
            {
                v[i]=1;
                n--;
            }
            }
           
        }
        else if(v[i-1]==0 and v[i]==0 and v[i+1]==0)
        {
           
            v[i]=1;
            n--;
        }
        if(n==0)
        {
            return 1;
        }
    }
        return n==0?1:0;
    }
};