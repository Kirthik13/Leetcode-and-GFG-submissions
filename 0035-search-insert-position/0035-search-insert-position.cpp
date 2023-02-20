class Solution {
public:
    int searchInsert(vector<int>& v, int k) {
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            
            // if(v[mid]==k) return mid;
            if(v[mid]>=k) r=mid-1;
            else l=mid+1;
        }
        return l;
//         lo = 0
//         hi = len(nums)

// while lo < hi:
// 	mid = (lo + hi) // 2
// 	if target <= nums[mid]:
// 		hi = mid
// 	else:
// 		lo = mid + 1

// return lo
        
        
    }
};