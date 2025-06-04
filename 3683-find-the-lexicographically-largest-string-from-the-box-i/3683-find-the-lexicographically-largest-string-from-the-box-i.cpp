class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size();
        int size = n - numFriends + 1;
        string ans = "";
        // cout << word.substr(2,5) << endl;
        for(int i=0; i<n; i++){
            if(word.substr(i, size).compare(ans) > 0){
                ans = word.substr(i,size);
            }
        }
        return ans;
    }
};