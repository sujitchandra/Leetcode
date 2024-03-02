class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') cnt++;
            if(s[i] == ')') cnt--;
            depth = max(depth, cnt);
        }
        return depth;
    }
};