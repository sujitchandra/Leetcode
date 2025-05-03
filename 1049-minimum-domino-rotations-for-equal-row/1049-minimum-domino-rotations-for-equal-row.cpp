class Solution {
    int minDominoRotationsSubfuntion(int val, vector<int>& tops, vector<int>& bottoms) {
        int ans_top = 0;
        int ans_bottom = 0;

        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != val && bottoms[i] != val) {
                return -1;
            } else if (tops[i] != val) {
                ans_top++;
            } else if (bottoms[i] != val) {
                ans_bottom++;
            }
        }

        return std::min(ans_top, ans_bottom);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = minDominoRotationsSubfuntion(tops[0], tops, bottoms);

        if (ans != -1 || tops[0] == bottoms[0]) {
            return ans;
        }

        return minDominoRotationsSubfuntion(bottoms[0], bottoms, tops);
    }
};