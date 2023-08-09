Intuition
The intuition behind this approach lies in the fact that if we have a certain maximum difference that satisfies the condition of forming p pairs with differences less than or equal to it, then any value smaller than this maximum difference will also satisfy the same condition.

By performing a binary search on the range of possible maximum differences, we effectively narrow down the search space and converge towards the smallest possible maximum difference that can still satisfy the condition. This is an optimization strategy that efficiently finds the solution without exhaustively checking all possible combinations.

In each iteration of the binary search, we check the feasibility of forming p pairs with differences less than or equal to the current midpoint value. If we can indeed form at least p pairs, it means that we can aim for a smaller maximum difference. On the other hand, if we can't form p pairs, we need to increase the maximum difference to ensure that we can achieve the required number of pairs.

Approach
Sort the array A in ascending order.

Initialize pointers: Set left to 0 and right to the maximum possible difference between the largest and smallest elements.

Binary Search Loop:

While left is less than right, do the following:
Calculate the midpoint mid between left and right.
Initialize a counter count to keep track of the pairs with differences less than or equal to mid.
Initialize an index i to 1 (starting from the second element).
Inner Loop:

While i is less than the array size, do the following:
If the difference between A[i] and A[i - 1] is less than or equal to mid, increment count.
Increment i by 2 to skip to the next potential pair.
Update Pointers:

If count is greater than or equal to p, update right to mid.
Otherwise, update left to mid + 1.
Return Result:

Once the binary search loop ends, return left.

Complexity
Time complexity:
O(N).

Space complexity:
O(N).


class Solution {
public:
    int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size();
        int left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2;
            int k = 0;
            int i = 1;
            while (i < n) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
                i++;
            }
            if (k >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};