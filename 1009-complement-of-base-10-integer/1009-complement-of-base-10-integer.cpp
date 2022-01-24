class Solution {
public:
    int bitwiseComplement(int n) {
//         if(n==0)
//         {
//             return 1;
//         }
//         int res=0;
//         int fac=1;
//         while(n!=0)
//         {
//             res=res+fac*((n%2==0)?1:0);
            
//             fac=fac*2;
//             n=n/2;
//         }
//         return res;
        
        return (n>0)? ((1LL << ((int)log2(n)+1))-1)^n
            :1;
    }
    
};