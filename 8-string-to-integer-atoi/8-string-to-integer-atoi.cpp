class Solution {
public:
    
    int myAtoi(string s) {
        
       long long  int n=s.size(),f=1,ans=0,p=0;
        // string k;
        int i=0;
        while(i<n and s[i]==' ')
        {
            i++;
        }
        if(i>=s.size())
        {
            return 0;
        }
        
         if(s[i]=='-' or s[i]=='+')
        {
                     f=(s[i]=='-')?-1:1;

            i++;
        }
        // i++;
       for(;i<n and isdigit(s[i])==1;i++)
       {
                ans=ans*10+(s[i]-48);   

       
               if(ans*f<=INT_MIN or ans*f>=INT_MAX)
               {
                   return f==1?INT_MAX:INT_MIN;
               }
             
                 
         
       }
        return ans*f;
    }
};