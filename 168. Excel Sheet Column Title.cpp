class Solution {
public:
    string convertToTitle(int n) {
        if (n < 27) {
            return string(1, 'A' + (n - 1) % 26);
        }
        string c = "";
        while (n > 0) {
            if (n % 26 == 0) {
                c += 'A' + 25;
                n -= 1;
            } else {
                c += 'A' + n % 26 - 1;
            }
            n /= 26;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};