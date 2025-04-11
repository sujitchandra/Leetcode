class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            string store = to_string(i);
            int size = store.size();
            if(size%2 != 0) continue;

            int middle = size/2;
            int leftsum = 0;
            int rightsum = 0;
            
            for(int i=0; i<middle; i++){
                leftsum += store[i] - '0';
            }
            for(int i=middle; i<size; i++){
                rightsum += store[i] - '0';
            }

            if(leftsum == rightsum) cnt++;

        }
        return cnt;
    }
};