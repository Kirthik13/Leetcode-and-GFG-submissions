class Solution {
public:
    bool cando(vector<int>& v, int max_speed,double hour)
    {
        double sum=0.0;
        for(int i=0;i<v.size();i++)
        {
             double curr=0.0;
            if(i!=v.size()-1)
            {
              curr=(double)(ceil(v[i]/(max_speed*1.0)));
            }
            else{
                curr=((v[i]/(max_speed*1.0)));
            }
            // cout<<"curr : "<<curr<<endl;
            
            sum+=curr;
           
        }
        return sum<=hour;
    }
    int minSpeedOnTime(vector<int>& v, double hour) {
            
        int l=1,r=1e9;
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            if(cando(v,mid,hour))
            {
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l==1e9?-1:l;
        
            
    }
};