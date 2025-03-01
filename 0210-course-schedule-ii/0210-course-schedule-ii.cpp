// NOT UNDERSTAND.. FULLY..

class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& topoOrder) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, topoOrder))
                    return true;
            } else if (pathVis[it]) {
                return true; // Cycle detected
            }
        }

        pathVis[node] = 0;
        topoOrder.push_back(node); // Add to topological order
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(numCourses, 0), pathVis(numCourses, 0), topoOrder;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis, topoOrder))
                    return {}; // Cycle detected, return empty list
            }
        }

        reverse(topoOrder.begin(), topoOrder.end()); // Reverse for correct order
        return topoOrder;
    }
};
