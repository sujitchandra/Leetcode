class Solution {
public:
    int nostud(vector<int>& arr, int pages){
    int n = arr.size();
    int stud = 1, pagesstudent = 0;
    for (int i=0; i<n; i++){
        if(pagesstudent + arr[i] <= pages){
            pagesstudent += arr[i];
        }
        else{
            stud++;
            pagesstudent = arr[i];
        }
    }
    return stud;
}

int findPages(vector<int>& arr, int n, int m) {
     if (m > n) {
        return -1;
    } 
    int low = *max_element(arr.begin() , arr.end());
    int high = accumulate(arr.begin(), arr.end() , 0);
    while(low <= high){
        int mid = (low+high)/2;
        int noofstud = nostud(arr, mid);
        if(noofstud > m) low = mid+1;
        else high = mid-1;  
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};