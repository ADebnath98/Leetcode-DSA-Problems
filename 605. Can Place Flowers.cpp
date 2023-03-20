class Solution {
public:
    bool canPlaceFlowers(vector<int>& vec, int n) {
        int ans = 0;
        int cnt = 0;
        vec.insert(vec.begin(),0);
        vec.push_back(0);
        vec.push_back(1);
        int num = vec.size();
        for(int i = 0;i<num;i++){
            if(vec[i]==0){
                cnt++;
            }
            else{
                if(cnt%2==0){
                    ans+=(max(0,(cnt/2)-1));
                }
                else{
                    ans+=(cnt/2);
                }
                cnt = 0;
            }
        }
        return ans>=n;
    }
};