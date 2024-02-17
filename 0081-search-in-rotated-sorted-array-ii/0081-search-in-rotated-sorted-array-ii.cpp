class Solution {
public:
    bool search(vector<int>& A, int k) {
         int n = A.size();
        int l = 0;
        int h = n-1;
        while(l <= h){
        int m = (l+h)/2;
        if(A[m] == k)
        return true;
        if(A[l] == A[m] && A[m] == A[h]){
            l = l+1;
            h = h-1;
            continue;
        }
        if(A[l] <= A[m]){
            if(A[l] <= k && k <= A[m]){
                h = m-1;
            }
            else
            l = m+1;
        } 
        else {
            if(A[m] <= k && k <= A[h])
            l = m+1;
            else
            h =m-1;
        }
    }
     return false;
    }
};