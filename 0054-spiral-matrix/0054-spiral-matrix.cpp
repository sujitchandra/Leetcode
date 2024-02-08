class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& MATRIX) {

   int n = MATRIX.size();
    if (n == 0) return {};
    int m = MATRIX[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(MATRIX[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return ans;
    }
};