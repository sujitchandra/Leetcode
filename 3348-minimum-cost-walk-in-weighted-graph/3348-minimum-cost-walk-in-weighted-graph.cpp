class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> arr(n, -1);
        vector<int> val(n, -1);
        for(auto edge: edges) {
            int a = edge[0];
            int b = edge[1];
            while(arr[a] >= 0) a = arr[a];
            while(arr[b] >= 0) b = arr[b];

            int bit = edge[2];
            if(val[a] != -1) bit &= val[a];
            if(val[b] != -1) bit &= val[b];

            if(a == b) {
                val[a] = bit;
            } else if(arr[a] <= arr[b]) {
                arr[a] += arr[b];
                arr[b] = a;
                val[a] = bit;
            } else {
                arr[b] += arr[a];
                arr[a] = b;
                val[b] = bit;
            }
        }

        vector<int> res;
        for(auto list: query) {
            int a = list[0];
            int b = list[1];
            while(arr[a] >= 0) a = arr[a];
            while(arr[b] >= 0) b = arr[b];
            if(a==b)
                res.push_back(val[a]);
            else 
                res.push_back(-1);
        }
        return res;
        
    }
};