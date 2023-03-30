class Solution {
 private:
  unordered_map<string, bool> Map;
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true ;
        if(s1.length() != s2.length())
            return false ;
        string hashedKey = s1 + '+' + s2;
        if(Map.find(hashedKey) != Map.end() )
            return Map[hashedKey] ;
        int n = s1.length() ;
        vector<int>alpha(26) ;
        for(int i = 0; i < n; i++){
            alpha[s1[i] -'a']++ ;
            alpha[s2[i] -'a']-- ;
        }
        for(int i = 0;i < 26; i++){
            if(alpha[i] != 0){
                Map[hashedKey] = false ;
                return false ;
            }
        }
        
        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
                Map[hashedKey] = true ;
                return true ;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i), s2.substr(0, n-i))){
                Map[hashedKey] = true ;
                return true ;
            }
        }
        Map[hashedKey] = false ;
        return false ;
    }
};