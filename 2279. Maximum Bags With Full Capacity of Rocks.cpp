class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0;
        int n= capacity.size();
        for (int i=0; i<n; i++){
            capacity[i]-= rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for (int i=0; i<n; i++){
            if (capacity[i]==0){
                ans++;
                continue;
            }
            if (additionalRocks-capacity[i]>=0){
                ans++;
                additionalRocks-= capacity[i];
            }
            else break;
        }

        return ans;
    }
};