class Solution {
public:  
    bool detectCapitalUse(string word) {
//we can write here also if size of word equals to 1 return true. as we are checking value for index 1 and you are thinging about error, but i have not written that just because of it is a string.
        if(word[1] >= 'A' && word[1] <= 'Z') 
        {
             for(int i = 0; i<word.size(); i++) if(word[i] >= 'a' && word[i] <= 'z') return false;
        }
        else for(int i = 1; i<word.size(); i++) if(word[i] >= 'A' && word[i] <= 'Z') return false;
        return true;
    }
};