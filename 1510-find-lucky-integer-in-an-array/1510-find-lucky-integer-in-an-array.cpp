class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int maxcnt = -1;
        unordered_map<int,int> freq;
        for(auto f : arr){
            freq[f]++;
        }
        for(auto [key , frequency] : freq){
            if(key == frequency) maxcnt = max(maxcnt, frequency); 

        }
        return maxcnt;
    }
};