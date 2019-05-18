class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int graph_size = graph.size();
        colors_ = vector<int>(graph_size, 0);
        for (int i = 0; i < graph_size; ++i) {
            if (colors_[i] == 0 && !dfs(graph, i, 1)) return false;
        }
        return true;
    }

private:
    vector<int> colors_;
    bool dfs(vector<vector<int>>& graph, int cur, int color) {
        colors_[cur] = color;
        for (const int &next : graph[cur]) {
            if (colors_[next] == color) return false;
            if (colors_[next] == 0 && !dfs(graph, next, -color)) return false;
        }
        return true;
    }
};