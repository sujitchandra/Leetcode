class Solution {
public:
    void merge( vector<int> &arr, int l, int mid, int r) {
    vector<int> ans;
    int left = l;
    int right = mid + 1;
    int cnt = 0; 
    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            ans.push_back(arr[left]);
            left++;
        } else {
            ans.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= r) {
        ans.push_back(arr[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
        arr[i] = ans[i - l];
}


int countpair(vector<int> &arr, int l, int mid, int r){
    long long right = mid + 1;
    long long cnt = 0;
    for (int i = l; i <= mid; i++) {
        while (right <= r && arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return (int)cnt;
}
    
int ms(vector<int> &arr, int l, int r) {
    int cnt = 0;
    if (l >= r)
        return cnt;
    int mid = (l + r) / 2;
    cnt += ms(arr, l, mid);
    cnt += ms(arr, mid + 1, r);
    cnt += countpair(arr, l,mid, r);
    merge(arr, l, mid, r);
    return cnt;
}

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return ms(nums , 0 , n-1);
    }
};