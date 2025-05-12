class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {        
        int n = digits.size();
        set<int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i != j && j != k && i != k){
                        int first = digits[i];
                        int mid = digits[j];
                        int last = digits[k];
                        if( first == 0) continue;
                        int num = first*100 + mid*10 +last;
                        if(num %2 == 0 ) st.insert(num);
                    }
                }
            }
        }
         return vector<int>(st.begin(), st.end());
    }
};