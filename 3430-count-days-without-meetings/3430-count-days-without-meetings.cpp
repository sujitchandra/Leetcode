class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int i,n=meetings.size(),k=0;
        vector<pair<int,int>>v;
        for(i=0;i<n;i++){
            v.push_back({meetings[i][0],meetings[i][1]});
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(i=0;i<n;i++){
            ans+=(max(0,v[i].first-k-1));
            k = max(k,v[i].second);
        }
        ans+=(max(0,days-k));
        return ans;
    }
};


