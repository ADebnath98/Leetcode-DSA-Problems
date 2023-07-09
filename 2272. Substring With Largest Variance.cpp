class Solution {
public:
    /* Take two chars ch1 and ch2. Keep comparing characters and increase frequency. */
    int largestVariance(string s) {
        vector<int> freq(26);
        for(auto ch: s)
            freq[ch - 'a']++;
        
        int ans = 0;
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if(ch1 == ch2 or !freq[ch1 - 'a'] or !freq[ch2 - 'a']) // if ch1 == ch2 or character not exits in string
                    continue;
                else {
                    for(int rev = 1; rev <= 2; rev++) {
                        int f1 = 0, f2 = 0;
                        for(auto ch: s) {
                            f1 += ch == ch1;
                            f2 += ch == ch2;

                            if(f1 < f2)
                                f1 = f2 = 0; // new Substring;
                            else if(f1 > 0 and f2 > 0)
                                ans = max(ans, f1 - f2);
                        }
                        reverse(s.begin(), s.end());
                    }
                }
            }
        }

        return ans;
    }
};