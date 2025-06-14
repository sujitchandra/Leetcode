class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        int n = str.length();
        int maxi = 0 , mini =0;
        char change = '-';
        int result = 0;

        for(int i=0; i<n; i++){

            maxi = str[i] - '0';
            mini = str[i] -'0';
            if(change == '-' && str[i] < '9') change = str[i];
            if(change != '-' && str[i] == change) maxi = 9;
            if(str[i] == str[0]) mini = 0;

            result = result * 10 + maxi - mini;
        }
        
        return result;
    }
};