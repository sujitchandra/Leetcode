#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int initialColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Base conditions
        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != initialColor) 
            return;

        // Change the color
        image[r][c] = newColor;
        
        // Move in all 4 directions
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            dfs(image, r + drow[i], c + dcol[i], initialColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        
        if (initialColor == color) return image; 
        
        dfs(image, sr, sc, initialColor, color);
        return image;
    }
};
