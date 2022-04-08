class Solution {
public:
    int missingNumber(vector<int>& v) {
			// int i=0;
			// int n = nums.size();
			// while(i<n)
			// {
			// int correctIdx = nums[i]; //where this element should be in sorted array
			// if(correctIdx<n && correctIdx != i) //if not already at correct position and correct position < n
			// {
			// swap(nums[i],nums[correctIdx]); //put current element at correct position
			// } 
			// else
			// 	i++; // move to next index
			// }
			// for(int i=0;i<n; i++)
			// if(nums[i]!=i)
			// return i;
			// return n;
        int i{},n=v.size();
        while(i<n)
        {
            int crctidx=v[i];
            // cout<<crctidx<<" ";
            if(crctidx<n and i!=crctidx)
            {
                swap(v[crctidx],v[i]);
            }
            else{
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(v[i]!=i) return i;
        }
        return n;
            
    }
};