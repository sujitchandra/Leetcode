class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
          int n = fruits.size();
        vector<bool> used(n, false); // Track used baskets

        int unplaced = 0;

        for (int i = 0; i < n; i++) {  // Process fruits in given order
            bool placed = false;

            for (int j = 0; j < n; j++) {  // Find the leftmost available basket
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true; // Mark basket as used
                    placed = true;
                    break;
                }
            }

            if (!placed) unplaced++; // If no basket found, count as unplaced
        }

        return unplaced;
    }
};