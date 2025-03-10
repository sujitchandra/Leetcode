// class Solution {
// public:
//     int countOfSubstrings(string word, int k) {
//         int n = word.length();
//         if(n < 5 ) return 0;


//         int cnt = 0;
//         // vector<char>ans(n);
//         // unordered_map<char,int> vowel;
       

//         // for(int i=0; i<n; i++){
//         //     vowel[word[i]]++;
//         // }

        

//         //     if(vowel.find('a') == vowel.end() && vowel.find('e') == vowel.end() &&
//         //     vowel.find('i') == vowel.end() && vowel.find('o') == vowel.end() &&
//         //     vowel.find('u') == vowel.end()){
//         //         return 0;
//         //     }
        

//         for(int j=0; j<n; j++){ 
//              bool isvowel[26] = {false};
//              int consonant_count = 0;
//             //  fill_n(isvowel,26,false);
//             for(int i = j; i<n; i++){
//                 if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' &&
//                 word[i] != 'u'){
//                     consonant_count ++;
//                     if(consonant_count > k) break;
//                 }
//                 isvowel[word[i] - 'a'] = true;

//                 if(isvowel['a' -'a'] && isvowel['e' -'a'] && isvowel['i' -'a'] && isvowel['o' -'a']
//                 && isvowel['u' -'a'] && consonant_count == k) cnt++;            
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int countOfSubstrings(string word, int k) {
        int n = word.size();
        if (n < k + 5)
            return 0;

        int l = 0, u = 0;
        int vowel = 0, conso = 0;
        unordered_map<char, int> mp;
        long long ans = 0, last_conso_index=-1;
        while (u < n) {
            if (isVowel(word[u])) {
                if (mp[word[u]] == 0) {
                    vowel++;
                }
                mp[word[u]]++;
            } else {
                mp[word[u]]++;
                conso++;
            }

            while (conso > k) {
                if (!isVowel(word[l]))
                {
                    conso--;
                    last_conso_index = l;
                    mp[word[l]]--;
                }
                else {
                    mp[word[l]]--;
                    if (mp[word[l]] == 0)
                        vowel--;    
                }
                l++;
            }

            while(conso==k && isVowel(word[l]) && mp[word[l]]>1)
            {
                mp[word[l]]--;
                l++;
            }
            if (vowel == 5 && conso == k) 
            {
                cout << "l=" << l << ",u=" << u << endl;
                ans+= (l-last_conso_index);
            }
            u++;
        }
        return ans;
    }
};