class Solution {
public:
    void help(string digit, string output, int ind, vector<string>&ans, string map[]){
        //base case
        if(ind == digit.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digit[ind] -'0'; //changing to integer 
        string value = map[number]; // geting value for that integer 
        for(int i=0; i<value.length();i++){ //looping through the value
            
            output.push_back(value[i]);
            help(digit,output,ind+1,ans,map);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length() == 0) return ans;
        string output = "";
        int ind = 0;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        help(digits,output,ind,ans,map);
        return ans;
    }
};