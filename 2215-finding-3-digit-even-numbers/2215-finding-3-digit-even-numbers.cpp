class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        vector<int> ans;

        for (int d : digits) {
            m[d]++;
        }

        for (int i = 100; i < 1000; i++) {
            if (i % 2 == 0) {
                int unit = i % 10;
                int ten = (i / 10) % 10;
                int hund = i / 100;

                m[unit]--;
                m[ten]--;
                m[hund]--;

                if (m[unit] >= 0 && m[ten] >= 0 && m[hund] >= 0) {
                    ans.push_back(i);
                }

                m[unit]++;
                m[ten]++;
                m[hund]++;
            }
        }

        return ans;
    }
};