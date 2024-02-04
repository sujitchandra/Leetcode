class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major = 0;
        
        for (int num : nums) {
            if (count == 0) {
                major = num;
            }
            
            if (num == major) {
                count++;
            } else {
                count--;
            }
        }
        
        return major;
        
        // without even below step it will run the below step is just checking
	// if the element has occured more than n times or not...

    // Count occurrences of potential majority element
    // count = 0;
    // for (int num : v) {
    //     if (num == major) {
    //         count++;
    //     }
    // }

    // // Check if the potential majority element is the actual majority
    // if (count > n / 2) {
    //     return major;
    // } else {
    //     return -1; // No majority element
    // }
        
    }
};
// sort(nums.begin(),nums.end());
        // int n = nums.size();
        // return nums[n/2];