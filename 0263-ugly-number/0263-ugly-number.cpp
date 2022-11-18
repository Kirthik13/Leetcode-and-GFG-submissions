class Solution {
public:
 
    bool isUgly(int num) {
        // for(int i=2;i*i<=n;i++)
        // {
        //     if(n%i==0)
        //     {
        //         for(int j=i;j<=n;j=j*2)
        //         {
        //             v[j]=1;
        //         }
        //     }
        // }
        
        while(num % 2 == 0 && num) num/=2;
        while(num%3 ==0 && num) num/=3; 
        // while(num%4 ==0 && num) num/=4;
        while(num%5 ==0 && num) num/=5;
        return num ==1;
    }
};