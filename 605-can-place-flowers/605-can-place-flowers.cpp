class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if(n==0)
        {
            return 1;
        }
        for(int i=0;i<v.size();i++)
    {
        // deb2(v[i],v[i-1]);
        // deb(v[i+1]);
        if(i==0)
        {
            if(v.size()>1){
            if(v[i]==0 and v[i+1]==0)
            {
                v[i]=1;
                n--;
                ++i;
            }
            }
            else{
                if(v[i]==0)
                {
                    v[i]=1;
                    n--;
                ++i;
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
                ++i;
            }
            }
           
        }
        else if(v[i-1]==0 and v[i]==0 and v[i+1]==0)
        {
            // cout<<"Asd";
            v[i]=1;
            n--;
                ++i;
        }
        if(n==0)
        {
            return 1;
        }
    }
        return n==0?1:0;
    }
};