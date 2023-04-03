class Solution {
public:
    int numRescueBoats(vector<int>& s, int n) {
     int l=0, r=s.size()-1, ans=0;
     sort(s.begin(), s.end());
     while(l<=r){
         int sum=s[l]+s[r];
         if(sum<=n){ans++, l++, r--;}
         else{ans++, r--;}
     }
     return ans;
    }
};