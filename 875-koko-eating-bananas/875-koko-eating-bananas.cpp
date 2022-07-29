class Solution {
public:
    bool cando(vector<int>&v,long long int speed,int h)
    {
        long long int time{};
        for(int i=0;i<v.size();i++)
        {
            long long a=(long long)v[i]/speed;
            long long b=(long long)v[i]%speed;
            time+=a;
            
            if(b>0){
                time++;
            }
        }
        
        return time<=h;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        long long int l=1;
        long long int r=*max_element(begin(v),end(v));
        
        while(l<r)
        {
            long long int mid=l+((r-l)/2);
            
            if(cando(v,mid,h))
            {
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        return l;
    }
};