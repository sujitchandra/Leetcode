class Solution {
public:
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxvowel = 0;
        int vowel = 0;

        for(int i=0; i<k; i++){
            if (isvowel(s[i])) vowel++;
        }
        maxvowel = vowel;
        for(int i=k; i< n; i++){
            if(isvowel(s[i])) vowel++;
            if(isvowel(s[i-k])) vowel--;
            maxvowel = max(maxvowel , vowel); 
        }
        return maxvowel;
    }
};