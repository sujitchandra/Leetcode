class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1000000007;
        int result = 0;
        int oddcnt = 0, evencnt = 1;
        int sum = 0; 
        int n = arr.size();

        for(int i=0; i<n; i++){
            sum += arr[i];

            if(sum % 2 == 0){
                evencnt++;
                result += oddcnt;
            }
            else {
                oddcnt++;
                result += evencnt;
            }
            result = result % mod;
        }
        
        return result;
    }
};