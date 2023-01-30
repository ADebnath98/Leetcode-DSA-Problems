/*Intuition
This is very simple and basic problem problem consisting of repeating steps.We solve this problem using the formula: Tn = Tn-1 + Tn-2 + Tn-3 ,where(T0 = 0, T1 = 1, T2 = 1)

Approach
Create 3 integer variables and initiate them with:
first = T0 = 0,
second = T1 = 1,
third = T2 = 1.
Make a fourth variable to store the fourth value.
Start a for loop from 3 to n and fill the fourth variable's value as sum of first 3 variables. After that shift the values to its respective predecessor.

Complexity
Time complexity: O(n)
Space complexity: O(1)*/

Code

class Solution {
public:
    int tribonacci(int n) {
        int first=0,second=1,third=1,fourth=0;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        for(int i=3;i<=n;i++)
        {
            fourth = first + second + third;
            first = second;
            second = third;
            third = fourth;
        }

        cout<<fourth;
        return fourth;
    }
};