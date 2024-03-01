// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.size();
//         if (n == 0) return 0;

//         int i = 0;
//         while (i < n && s[i] == ' ') i++; // checking for leading space..

//         s = s.substr(i); //store everything after leading space

//         int sign = +1;
//         long long ans = 0;

//         if (s[0] == '-') sign = -1; // for sign 

//         int max_val = INT_MAX, min_val = INT_MIN;

//         i = (s[0] == '+' || s[0] == '-') ? 1 : 0; // if 1st char is + or - start from 2nd char

//         while (i < n) {
//             if (s[i] == ' ' || !isdigit(s[i])) break; //if there is no digit

//             ans = ans * 10 + s[i] - '0';

//             if (sign == '+' && ans > max_val) return max_val;
//             if (sign == '-' && -1 * ans < min_val) return min_val;

//             i++;
//         }
//         return (int)(sign * ans);
//     }
// };

class Solution {
    public :
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;
         while(i<s.size() && s[i]== ' ') {
             i++;
         }     
        s = s.substr(i); //i ---> last of string
        
        int sign = +1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1;
        
        int MAX = INT_MAX, MIN = INT_MIN;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
		
        while(i < s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + s[i]-'0';
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
        }
        
        return (int)(sign*ans);
    }
};