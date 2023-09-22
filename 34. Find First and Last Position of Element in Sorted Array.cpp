Approach
So now we r going to apply binary search in this question so we have to remind one think that in binary search if you find the element then you return it directly , but in this question we have to return first and the last occurence of the solution so for this we have to apply binary search after we got target == nums[mid]. **And main point we have to split the process into first occurence amd the last occurence **

Complexity
Time complexity:
O(logn)

Space complexity:
O(1)


class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>v;
        v.push_back(-1);
        v.push_back(-1);
        int start =0 , end = nums.size() -1  ;
       
        int mid = (start+end)/2;
        
        //first occurences 
        while(start <= end){
           
            int mid = (start+end)/2;

            if(nums[mid] == target){
                v[0] = mid;
                end = mid - 1 ;
            }
            else if(nums[mid] < target){
                start = mid +1;
            }
            else{
                end  = mid - 1;
            }
        }
        //last occurences 
        start = 0, end = nums.size()-1;
         
         while(start <= end){
            
            int mid = (start+end)/2;

            if(nums[mid] == target){
                v[1] = mid;
                start = mid + 1 ;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return v;
    }
};
