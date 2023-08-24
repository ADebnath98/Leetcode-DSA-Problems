Intuition
Intuition is to consider a given range of words till it in within the max range including single space, as soos as we get the range we can build a justified string with calculaing the total length of words and spaces required. At last we can make left justfied string for last string.

Approach
There are two fn buildStr and buildLastStr, I highly recommomend to do a dry run with given test cases you will definitely understand.

Complexity
Time complexity: O(n∗maxWidth)O(n * maxWidth)O(n∗maxWidth)
Space complexity: O(1)O(1)O(1)



class Solution {
public:
    // Fn to build string from given range
    string buildStr(int start, int end, int mw, vector<string> &words, int len) {
        // Calculate the spaces req and extra gaps
        int n = end - start;
        int spaces = mw - len;
        // Each regular gap space
        int eachSpace = n >= 1 ? spaces / n : 0;
        // Extra will be distributed from left
        int remSp = n >= 1 ? spaces % n : 0;
        string ans = words[start];

        for (int i = start + 1; i <= end; i++) {
            int reqSpaces = eachSpace + (remSp-- > 0);
            string sp(reqSpaces, ' ');
            ans += sp + words[i];
        }

        if(n == 0){
            string sp(mw - words[start].length(), ' ');
            ans = ans + sp;
        }

        return ans;
    }

    // func to build last justifed string
    string buildLastStr(int start, vector<string> &words, int mw) {
        string ans = words[start];
        int len = ans.length();
        
        // Add words by single spaces 
        for (int i = start + 1; i < words.size(); i++) {
            ans += " " + words[i];
            len += words[i].length() + 1;
        }

        // Add remaining spaces
        if (len < mw) {
            ans += string(mw - len, ' ');
        }

        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start = 0;
        int len = words[0].length();
        int spaces = 1;

        for (int end = 1; end < words.size(); end++) {
            int newLen = len + words[end].length();
            if (newLen + spaces > maxWidth) {
                // build string from start till valid length
                ans.push_back(buildStr(start, end-1, maxWidth, words, len));
                
                // reset the variables
                start = end;
                spaces = 1;
                len = words[end].length();
            } else {
                len = newLen;
                spaces++;
            }
        }
        
        // Building last justified string
        ans.push_back(buildLastStr(start, words, maxWidth));
        return ans;
    }
};