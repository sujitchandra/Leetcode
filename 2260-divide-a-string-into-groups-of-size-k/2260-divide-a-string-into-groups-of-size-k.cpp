class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> vec;
        bool filled = false;
        string temp = "";
        for(int i = 0;i < s.size();i++){
            if(temp.size() < k){
                temp += s[i];
            }
            else{
                vec.push_back(temp);
                temp.clear();
                temp += s[i];
            }
        }

        if(temp.size() == k){
            vec.push_back(temp);
            return vec;
        }

        while(temp.size() < k){
            filled = true;
            temp += fill;
        }
        if(filled)
            vec.push_back(temp);
        return vec;

    }
};