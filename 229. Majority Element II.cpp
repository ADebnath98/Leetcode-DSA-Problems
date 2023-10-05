class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        if (n == 0)
        {
            return result;
        }
        
        unordered_map<int, int> count;

        for (int num : nums) 
        {
            count[num]++;
            if (count[num] > n / 3) 
            {
                if (find(result.begin(), result.end(), num) == result.end()) 
                {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};
