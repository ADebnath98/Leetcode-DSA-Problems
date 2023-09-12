class Solution {
public:
    bool checkPerfectNumber(int nums) {
        
        int ans = 0;

        for ( int i=1; i*i<=nums; i++ ) {

            if ( nums%i == 0 ) {

                ans += i;

                if ( i*i != nums ) {
                    ans += nums/i;
                }
            }

            if ( ans-nums > nums ) {
                return 0;
            }
        }

        if ( ans-nums == nums ) {
            return 1;
        }

        return 0;
    }
};