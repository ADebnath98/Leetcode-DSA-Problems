class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long count = 0;
        for(char ch: s) {
            if(isdigit(ch)) {
                int num = ch-'0';
                if(count < k && k <= count*num) {
                    if(k%count == 0) {
                        return decodeAtIndex(s, count);
                    }
                    else {
                        return decodeAtIndex(s, k%count);
                    }
                }
                count = count*num;
            }
            else {
                count++;
                if(count == k) {
                    string res = "";
                    res += ch;
                    return res;
                }
            }
        }
        return "-1";
    }
};

