Intuition
If we need to find out which is the closest charechter to 'target', why not we use thier ASCII Values?

Approach
Calculating differece between a Charecter in 'letters' array and 'target'
if the difference is greater than '0', then this is the nearest charecter the 'target', as the 'leters' array is non-decreasingly sorted
Complexity
Time complexity: O(N)
Space complexity: O(1)
Code

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int dif = INT_MAX;
        for(int i = 0; i< letters.size(); i++){
            dif = (int)letters[i] - (int)target;
            if(dif>0)
                return letters[i];
        }
        return letters[0];
    }
};