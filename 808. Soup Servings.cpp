Intuition
We have to calculate the probability of serving the entire soup. The probability depends on different combinations of servings of ingredient A and ingredient B.

Approach
If n is greater than 4800, the function returns 1 because it's highly likely that the entire soup will be served. This is an optimization to handle large inputs.
Create a 2D array dp to store previously computed probabilities to avoid redundant calculations during recursion.
Call the helper function with initial parameters (n, n, 1) to calculate the probability of serving the entire soup.
In the helper function:
If remA is less than or equal to 0 and remB is greater than 0, it means there is still some ingredient B left, and the probability is currProb.
If both remA and remB are less than or equal to 0, it means both ingredients are empty, and the probability is currProb/2.
If both remA and remB are greater than 0, the function checks if the probability for the given state has already been computed (stored in dp).
If so, return the precomputed value.
If not, compute the probability for four different scenarios:
Serve 100 ml of A and move to the next state with remA-100 and remB.
Serve 75 ml of A and 25 ml of B and move to the next state with remA-75 and remB-25.
Serve 50 ml of A and 50 ml of B and move to the next state with remA-50 and remB-50.
Serve 25 ml of A and 75 ml of B and move to the next state with remA-25 and remB-75.
Sum up the probabilities for these four scenarios and store the result in dp.
Finally, return the calculated probability for serving the entire soup.
NOTE: The approach uses recursion with memoization to efficiently calculate the probability of serving the entire soup based on different serving scenarios for ingredients A and B.

Complexity
Time complexity:
O(1)

Space complexity:
O(n^2)
as its a 2d dp


using namespace std;

class Solution {
public:
    double soupServings(int n) {
        // If 'n' is greater than 4800, it's highly likely that the entire soup will be served.
        // So, return 1 as an optimization for large inputs.
        if (n > 4800)
            return 1.0;

        // Initialize the memoization array 'dp' with dimensions (n/25+1) x (n/25+1).
        vector<vector<double>> dp(n / 25 + 1, vector<double>(n / 25 + 1, -1));

        // Call the 'helper' function with initial parameters (n, n, 1) to calculate the probability of serving the entire soup.
        return helper(n, n, 1.0, dp);
    }

private:
    // Recursive function to calculate the probability of serving the entire soup.
    double helper(int remA, int remB, double currProb, vector<vector<double>>& dp) {
        double res = 0.0;

        // If remA is less than or equal to 0 and remB is greater than 0,
        // it means there is still some ingredient B left, and the probability is 'currProb'.
        if (remA <= 0 && remB > 0)
            res = currProb;

        // If both remA and remB are less than or equal to 0,
        // it means both ingredients are empty, and the probability is 'currProb/2'.
        else if (remA <= 0 && remB <= 0)
            res = currProb / 2.0;

        // If both remA and remB are greater than 0, compute the probability for the given state.
        else if (remA > 0 && remB > 0) {
            // If the probability for the current state has already been computed (stored in 'dp'),
            // return the precomputed value to avoid redundant calculations.
            if (dp[remA / 25][remB / 25] != -1)
                return dp[remA / 25][remB / 25];

            // Compute the probability for four different scenarios:
            // a. Serve 100 ml of A and move to the next state with 'remA-100' and 'remB'.
            // b. Serve 75 ml of A and 25 ml of B and move to the next state with 'remA-75' and 'remB-25'.
            // c. Serve 50 ml of A and 50 ml of B and move to the next state with 'remA-50' and 'remB-50'.
            // d. Serve 25 ml of A and 75 ml of B and move to the next state with 'remA-25' and 'remB-75'.
            res = 0.25 * (helper(remA - 100, remB, currProb, dp) +
                         helper(remA - 75, remB - 25, currProb, dp) +
                         helper(remA - 50, remB - 50, currProb, dp) +
                         helper(remA - 25, remB - 75, currProb, dp));

            // Store the computed probability for the current state in 'dp'.
            dp[remA / 25][remB / 25] = res;
        } else {
            return 0.0;
        }

        return res;
    }
};