class Solution {
public:
    bool halvesAreAlike(string s) {
        int length = s.size();
        int half = length/2;

        int vowelCount1 = 0, vowelCount2 = 0;
    
        for(int i=0;i<half;i++) {    
            char ch = s[i];
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++vowelCount1;
            }
        }
        for(int i=half;i<length;i++) {
            char ch = s[i];
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++vowelCount2;
            }
        }

        if(vowelCount1 == vowelCount2) return true;
        return false;
    }
};
