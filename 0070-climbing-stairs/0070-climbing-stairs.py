class Solution:
    def climbStairs(self, n: int) -> int:
        if n==2 :
                return 2
        if n==1 :
                return 1
        
        
        
        
       
        
        
        
        
        a=1
        prev=2
    
        for i in range(3, n+1):
                  
            curr=a+prev;
            a=prev;
            prev=curr;
        
        
        return prev
        
     
        
        
     
        