class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        
        vector<int>count1(26, 0);
        vector<int>count2(26, 0);
        
        for(int i=0;i<word1.length();i++)
            count1[word1[i] - 'a']+=1;
        
        for(int i=0;i<word2.length();i++)
            count2[word2[i] - 'a']+=1;
        
        for(int i=0;i<26;i++){
            if((count1[i] > 0 && count2[i] == 0) || (count1[i] == 0 && count2[i] > 0))
                return false;
        }
        
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
                return false;
        }
        
        return true;
    }
};