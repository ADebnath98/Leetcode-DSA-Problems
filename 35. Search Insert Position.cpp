Intuition
After seeing this question, first thought to solve this question came to my mind is by using searching. As sorted array/vector is given then searching algorithm must be binary search.

Approach
Here in this question we also had to return the expected position of target if target is not present in array. So we use binary search, if target is present in the array then simply returning the index is sufficient. But if target is not present, we have to return the index i.

Complexity
Time complexity:
O(logn)O(logn)O(logn)

Space complexity:
O(n)O(n)O(n)


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0; // first index
        int j = nums.size()-1; // last index
        while(i<=j){ // if fail , then i will be expected position
            int m = i+(j-i)/2;
            if(nums[m]==target){
                return m; // target is present in array returning index
            }else if(nums[m]>target){
                j = m-1;
            }else{
                i = m+1;
            }
        }
        return i; // returning expected position of target
    }
};