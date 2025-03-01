class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]); 
            indegree[edge[0]]++;
        }

        queue<int> q;
        int count = 0; 

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++; 

            for (int neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we processed all courses, return true (no cycle)
        return count == numCourses;
    }
};
