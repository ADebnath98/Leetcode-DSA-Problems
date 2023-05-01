class Solution {
public:
    double average(vector<int>& salary) {
        return double(accumulate(begin(salary), end(salary), 0) - *max_element(begin(salary), end(salary)) - *min_element(begin(salary), end(salary))) / double(salary.size() - 2);
    }
};