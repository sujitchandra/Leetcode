#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> bobpath(n, -1);
        vector<int> path;
        fillbobpath(bob, -1, path, graph);

        for(int i = 0; i < path.size(); i++){
            bobpath[path[i]] = i; 
        }

        return alicemax(0, -1, 0, bobpath, graph, 0, amount);
    }

private:
    bool fillbobpath(int node, int parent, vector<int>& path, vector<vector<int>>& graph) {
        if (node == 0) return true;
        for (auto neighbour : graph[node]) {
            if (neighbour != parent) {
                path.push_back(node);
                if (fillbobpath(neighbour, node, path, graph)) return true; 
                path.pop_back();
            }
        }
        return false;
    }

    int alicemax(int node, int parent, int currsum, vector<int>& bobpath, vector<vector<int>>& graph,
                 int timestamp, vector<int>& amount) {
        if (bobpath[node] == -1 || bobpath[node] > timestamp) {
            currsum += amount[node];
        }
        else if (bobpath[node] == timestamp) {
            currsum += amount[node] / 2;
        }

        if (graph[node].size() == 1 && node != 0) return currsum;

        int maxi = INT_MIN;
        for (auto neighbour : graph[node]) {
            if (neighbour != parent) {
                maxi = max(maxi, alicemax(neighbour, node, currsum, bobpath, graph, timestamp + 1, amount)); 
            }
        }
        return maxi;
    }
};