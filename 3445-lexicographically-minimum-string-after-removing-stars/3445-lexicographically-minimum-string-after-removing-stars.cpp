class Solution {
public:
    string clearStars(string s) {
        int n =s.size();
        priority_queue<char, vector<char> , greater<char>> pq;
        unordered_map<char , vector<int>> mp;
        vector<bool> b(n, true);

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                char temp = pq.top();
                pq.pop();
                int last_smallest = mp[temp].back();
                mp[temp].pop_back();
                b[i] = false;
                b[last_smallest] = false;
            }
            else{
                pq.push(s[i]);
                mp[s[i]].push_back(i);
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(b[i]) ans += s[i];
        }

        return ans;
    }
};