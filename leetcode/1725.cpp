class Solution {
  public:
    int countGoodRectangles(vector<vector <int>>& rectangles) {
      int cur = 0, count = 0;
      for (auto it : rectangles) {
        int w = it[0], h = it[1];
        if (min(w, h) == cur) {
          count++;
        } else if (min(w, h) > cur) {
          cur = min(w, h);
          count = 1;
        }
      }
      return count;
    }
};
