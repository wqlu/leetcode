vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    typedef pair<double, vector<int>> pi;
    priority_queue<pi, vector<pi>, greater<pi>> p;
    for (const auto &point : points) {
        double distance = sqrt(pow((double)point[0], 2.0) + pow((double)point[1], 2.0));
        p.push(make_pair(distance, point));
    }
    vector<vector<int>> ans(K);
    for (int i = 0; i < K; ++i) {
        ans[i] = p.top().second;
        p.pop();
    }
}