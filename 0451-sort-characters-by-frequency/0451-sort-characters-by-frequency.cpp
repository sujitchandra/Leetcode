class Solution {
public:
    bool static cmp(pair<char,int>&a , pair<char,int>&b){
        return a.second > b.second; // sort in decending order 
    }
    
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++; //storing in the map
        
        vector<pair<char,int>> v;
        for(auto i:mp)
            v.push_back({i.first,i.second}); // storing int vector so we can sort and return
        
        sort(v.begin(), v.end(), cmp); //sort 
        
        for(auto x:v){ //iterating vector
            for(int i=0; i<x.second; i++) // running till the frequency which is in second
            {
                ans += x.first; // storing according to frequency
            }
        }
        return ans;
    }
};