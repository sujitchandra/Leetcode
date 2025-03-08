class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int mini = INT_MAX;
            for (int i = 0; i <= blocks.size() - k; i++) {
            int total_white = 0; 
            
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') total_white++;
            }
            
            mini = min(mini, total_white);
        }

        return mini;


    }
};