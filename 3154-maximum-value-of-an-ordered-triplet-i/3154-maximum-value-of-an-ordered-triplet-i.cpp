class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // int n = nums.size();
        long maxi = 0;
        long taxi = 0;
        long sexi = 0;
        for(long num : nums){
            maxi = max(maxi, taxi * num); // max value of triplet
            taxi = max(taxi, sexi - num); // highest difference
            sexi = max(sexi, num); // maximum number 
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};

