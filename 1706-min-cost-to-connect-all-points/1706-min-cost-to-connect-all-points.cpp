class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //using prim's algorithm..
        int V = points.size();
        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                // x2-x1 + y2-y1 to calculate weight
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt}); 
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (auto& [adjNode, edW] : adj[node]) {
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};
