#include <cstdlib>
class Solution {
public:
   std::vector<int> asteroidCollision(std::vector<int>& as) {
        std::vector<int> result;

        for (int i = 0; i < as.size(); i++) {
            if (result.empty() || as[i] > 0) {
                result.push_back(as[i]);
            } else {
                while (!result.empty() && result.back() > 0 && result.back() < abs(as[i])) {
                    result.pop_back();
                }

                if (result.empty() || result.back() < 0) {
                    result.push_back(as[i]);
                } else if (result.back() == abs(as[i])) {
                    result.pop_back();
                }
            }
        }

        return result;
    }
};