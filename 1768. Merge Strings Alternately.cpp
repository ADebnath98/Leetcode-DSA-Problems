Intuition
Use 2 pointers to traverse both string simultaneously and add word1[i]+word2[j] to the ans string.
If any string is left out then add the remaining letters to the ans string.

Approach
Initialize i and j as 0,and string ans as empty string.
While i is less than word1.size() and j is less than word2.size() add word1[i] and word2[j] to the ans string and increment both pointers.
If any string is longer then other then just add the remaining characters by using a while loop for the longer string.
Complexity
Time complexity:O(max(n,m))
Space complexity:O(n+m)
Where n is length of word1 and m is length of word2



class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string ans="";
        while(i<word1.size() and j<word2.size()){
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
        }
        while(i<word1.size()) {
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()) {
            ans+=word2[j];
            j++;    
        }
        return ans;
    }
};