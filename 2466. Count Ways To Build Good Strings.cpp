Intuition
Start with the empty string "" and add either one or zero gradually at each recursive step.

Like below for case, one = 1 and zero = 2:
-> initially the string is empty "".
-> recursion 1:

Either Include one, so string will become "1".
Or include zero, so string will become "00".
-> recursion 2:

Either Include one, so string will become either "11" or "001".
Or include zero, so string will become "100" or "0000".
so on......

The other thing to notice is that using string as a recursion parameter, works for recurssion solution but does not work for dp solution, because consider a case, where:

string 1 = "1001001"
string 2 = "0010011"

string 1 and string 2 both will bring same results. But if we consider string as recursion parameter then in dp string 1 and string 2 will be considered as two different states and recomputation will happen.

Also as here we are not concerned about actuall string, we only care about its length. So, instead of taking string we take length as our recussion parameter. So solution will become:

Like below for case, one = 1 and zero = 2:
-> initially the string is empty, so size is 0.
-> recursion 1:

Either Include one, so string will become of size 1.
Or include zero, so string will become of size 2.
-> recursion 2:

Either Include one, so string will become of size either 2 or 3.
Or include zero, so string will become of size 3 or 4.
so on......

(don't forget to count only those cases where length is between low and high).

Approach
See code for explanation.

Complexity
Time complexity: O(high) -- because max calls will be high.

Space complexity: O(high) -- maximum depth of recursion.





class Solution {
private:
    int mod = 1e9 + 7;

public:
    int solve(int low, int high, int zeros, int ones, int initial_string_size, vector<int>& dp){

        if(initial_string_size > high){
            return 0;
        }

        if(dp[initial_string_size] != -1){
            return dp[initial_string_size];
        }

        int included_ones = solve(low, high, zeros, ones, initial_string_size + ones, dp) % mod;
        int included_zeros = solve(low, high, zeros, ones, initial_string_size + zeros, dp) % mod;
        int ans = (included_ones + included_zeros) % mod;

        if(initial_string_size >= low){
            return dp[initial_string_size] = ans+1;
        }

        return dp[initial_string_size] = ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        

        // Top-down dp solution ---------------------------
        // vector<int> dp(high+1, -1);
        // return solve(low, high, zero, one, 0, dp);

        // Bottom-Up solution -----------------------------
        vector<int> dp(high+1, 0);
        int included_ones = 0, included_zeros = 0, ans = 0;
        for(int i = high; i >= 0; i--){
            included_ones = 0; included_zeros = 0; ans = 0;
            if(i + one <= high){
                included_ones = dp[i+one];
            }
            if(i+zero <= high){
                included_zeros = dp[i+zero];
            }
            ans = (included_ones % mod + included_zeros % mod) % mod;
            if(i >= low){
                ans += 1;
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};