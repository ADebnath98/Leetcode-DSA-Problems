class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0];
        vector<bool> result(candies.size(),false);
        for(int i =0; i < candies.size(); i++) 
            if(candies[i] >= max) max = candies[i];
        for(int i= 0; i < candies.size();i++)
            result[i] = (candies[i] + extraCandies >= max ); 
        return result;
    }
};