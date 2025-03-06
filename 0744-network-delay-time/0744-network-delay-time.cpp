class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < m; i++){
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> ans(n + 1, 1e9);
        ans[k] = 0;


        while(!pq.empty()){
            int time = pq.top().first;
            int nd = pq.top().second;
            pq.pop();


            for(auto& it : adj[nd]){
                if(time + it.first < ans[it.second]){
                    ans[it.second] = time + it.first;
                    pq.push({ans[it.second], it.second});
                }
            }
        }

        int maxi = 0;
        for(int i = 1; i <= n; i++){
            // cout << ans[i] << endl;
            if(ans[i] == 1e9) return -1;
            maxi = max(maxi, ans[i]);
        }
        return maxi;
    }
};