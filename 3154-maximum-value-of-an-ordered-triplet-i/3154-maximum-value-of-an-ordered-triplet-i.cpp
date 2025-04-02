class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // int n = nums.size();
        long maxi = 0;
        long taxi = 0;
        long sexi = 0;
        for(int num : nums){
            maxi = max(maxi, (long)taxi * num);
            taxi = max(taxi, (long)sexi - num);
            sexi = max(sexi, (long)num);
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};

