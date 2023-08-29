class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int yes=0,no=0;
        for(auto &it: customers){
            if(it=='Y') yes++;
        }    

        int res;
        int minPenalty=1e9+7;
        
        for(int i=0;i<=n;i++){
            int penalty =yes+no;
            if(i!=n&&customers[i]=='N') {
                no++;
            }
            if(i!=n&&customers[i]=='Y'){
                yes--;
            }
            if(penalty<minPenalty){
                minPenalty=penalty;
                res=i;
            } 
        }
        return res;
    }
};