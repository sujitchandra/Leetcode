class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int odd = 0;
        int even = s.size();

        for(auto c : s){
            freq[c-'a']++;
        }

        for(int f : freq){
            if(f %2 != 0) odd = max(odd , f);
            else if(f != 0) even = min(even , f);
        }
        return odd - even;
    }
};