class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        int n=s.size();
// first calculating the the numbers of vowels in window
        for(int i=0;i<k;i++){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') count++;
        }
         ans=max(count,ans);
// iterating the window in string s
         for(int i=k;i<n;i++){
                int m=i-k;
// adding a element in window
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') count++;
//removing a element the first element of window
                if(s[m]=='a'||s[m]=='e'||s[m]=='i'||s[m]=='o'||s[m]=='u') count--;
                ans=max(ans,count);
        }
        return ans;
    }
};