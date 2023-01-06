class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(), costs.end());
        for(int i = 0; i < costs.size(); i++){
            if(coins - costs[i] >=0 ){
                count ++;
                coins = coins - costs[i];
            }
        }

        return count;
    }
};





class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]>coins) break;
            coins-=costs[i];
            ++ans;
        }   
        return ans;
    }
};





class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int cnt = 0;
        for(auto i: costs){
            if(i<=coins){
                cnt++;
                coins -= i;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};