class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int bottom=n;
        int right=n;
        int left=0,top=0;
        vector<vector<int>>ans(n,vector<int>(n,0));
        int val=1;
        while(val<=n*n){
                for(int i=left;i<right;i++){
                    ans[top][i]=val;
                    val+=1;
                }
                top++;
                for(int i=top;i<bottom;i++){
                    ans[i][right-1]=val;
                    val+=1;
                }

                right--;
                for(int i=right-1;i>=left;i--){
                    ans[bottom-1][i]=val;
                    val+=1;
                }
                bottom--;
                for(int i=bottom-1;i>=top;i--){
                    ans[i][left]=val;
                    val+=1;
                }
                left++;
        }
        return ans;
    }
};

   