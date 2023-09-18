class Solution {
public:
static bool comp(vector<int>& a , vector<int>& b){
    if(a[0] == b[0])return a[1]<b[1];
    return a[0]<b[0];
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i  <  mat.size() ; i++){
            cnt = 0;
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(mat[i][j] == 1)cnt++;
                else break;
            }
            mat[i][0]=cnt;
            mat[i][1]=i;
            // asn.push_back(i);
        }
        sort(mat.begin() , mat.end(), comp);
        for(int i= 0 ; i < k ; i ++){
            ans.push_back(mat[i][1]);
        }
        return ans;
    }
};