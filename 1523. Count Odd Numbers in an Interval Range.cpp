class Solution {
public:
    int countOdds(int low, int high) {
        int count = (high - low)/2;

        if(high&1 || low&1)
        {
            count ++;
        }
        return count;
    }
};