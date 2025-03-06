#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        vector<long long> dist(n, LLONG_MAX); 
        vector<int> ways(n, 0); 
        int mod = 1e9 + 7;

        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

           
            for (auto& [adjNode, edW] : adj[node]) {
                long long newDist = dis + edW;

             
                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node]; 
                    pq.push({newDist, adjNode});
                }

                else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod; 
    }
};
