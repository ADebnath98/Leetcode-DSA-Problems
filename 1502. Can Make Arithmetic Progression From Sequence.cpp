class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int old_d = arr[1] - arr[0];

        int n = arr.size();

        int new_d = 0;

        for(int i=0;i<n-1;i++){
            new_d = arr[i+1] - arr[i];
            if(new_d != old_d){
                return false;
            }
        }
        return true;
    }
};