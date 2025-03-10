class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        if(n < 5 ) return 0;


        int cnt = 0;
        // vector<char>ans(n);
        // unordered_map<char,int> vowel;
       

        // for(int i=0; i<n; i++){
        //     vowel[word[i]]++;
        // }

        

        //     if(vowel.find('a') == vowel.end() && vowel.find('e') == vowel.end() &&
        //     vowel.find('i') == vowel.end() && vowel.find('o') == vowel.end() &&
        //     vowel.find('u') == vowel.end()){
        //         return 0;
        //     }
        

        for(int j=0; j<n; j++){ 
             bool isvowel[26] = {false};
             int consonant_count = 0;
            //  fill_n(isvowel,26,false);
            for(int i = j; i<n; i++){
                if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' &&
                word[i] != 'u'){
                    consonant_count ++;
                    if(consonant_count > k) break;
                }
                isvowel[word[i] - 'a'] = true;

                if(isvowel['a' -'a'] && isvowel['e' -'a'] && isvowel['i' -'a'] && isvowel['o' -'a']
                && isvowel['u' -'a'] && consonant_count == k) cnt++;            
            }
        }
        return cnt;
    }
};