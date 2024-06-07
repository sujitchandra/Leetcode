class Solution {
public:
    int setbits(int n)
    {
        int count = 0;
        for(int i = 0; i <= 31; i++) {
            if((n & (1 << i)) != 0) {
                count++;
            }
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(setbits(i)); 
        }
        return ans;
    }
};
