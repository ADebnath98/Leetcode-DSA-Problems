class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int time = 0;
    sort(begin(courses), end(courses),
         [](auto& a, auto& b) { return a[1] < b[1]; });
    priority_queue<int> maxHeap;

    for (auto& c : courses) {
      int duration = c[0];
      int lastDay = c[1];
      maxHeap.push(duration);
      time += c[0];
      if (time > lastDay)
        time -= maxHeap.top(), maxHeap.pop();
    }

    return maxHeap.size();
  }
};