Intuition
The repeating number's operated together can indicate their presence.

Approach
Here following the space complexity constraint.

We can sort it first.
Then which traversing comparing the adjacent via bitwise-XOR.
The Bitwise XOR gives 0 if the two numbers are same.
Complexity
Time complexity:

O(nlogn)O(nlogn)O(nlogn)

Space complexity:

O(1)O(1)O(1)



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)if(!(nums[i]^nums[i+1]))return nums[i];
        return -1;
    }
};