class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // if there is no. common divisor     
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }
        // find the length of greatest common divisor        
        int gcd_length = __gcd(str1.size(), str2.size());        
        // return gcd       
        return str1.substr(0, gcd_length);
    }
};