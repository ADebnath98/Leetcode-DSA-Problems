class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() == numRows || numRows == 1)
            return s;

        string ans;
        int i = 0, n = s.size(), r = 0;
        bool rev = false;
        vector<string> vec(n, "");

        while(i < n){
            vec[r] += s[i++];

            if(rev)
                r--;
            else
                r++;

            if(r == numRows){
                rev = true;
                r = numRows-2;
            }else if(r == -1){
                rev = false;
                r = 1;
            }
        }
        
        for(string& str: vec)
            ans += str;

        return ans;
    }
};