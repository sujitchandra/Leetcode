class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int totalwhite = 0;
        int mini = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] =='W') totalwhite++;
        }

        mini = totalwhite;

        for(int i=k; i<n; i++){

            if(blocks[i-k] == 'W') totalwhite --;
            if(blocks[i] == 'W') totalwhite ++;
            mini = min(mini , totalwhite);
        }
        return mini;


    }
};