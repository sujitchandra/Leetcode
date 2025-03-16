class Solution {
public:

    bool helper(vector<int>& ranks , int cars , long long mid){
        long long totalcar = 0;
            for(int rank:ranks){
                totalcar += sqrt( mid/ rank);
            }
        return totalcar >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) { 
        long long left = 1;
        long long right = 1e14;
        while(left < right){
            long long mid = left + (right - left) /2;
            if(helper(ranks , cars , mid)){

                right = mid;
            }
           else{
            left = mid + 1;
           }
        }
        return left;
    }
};