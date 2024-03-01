
class Solution {
    public :
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;
         while(i<s.size() && s[i]== ' ') { //checking for leading space
             i++;
         }     
        s = s.substr(i); //going from i ---> last of string
        
        int sign = +1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1; // for sign
        
        int MAX = INT_MAX, MIN = INT_MIN;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0; // if 1st char is + or - start from 2nd char
		
        while(i < s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break; //if there is no digit
            
            ans = ans * 10 + s[i]-'0';
            
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
        }
        
        return (int)(sign*ans);
    }
};