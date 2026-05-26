class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lowerCase, upperCase;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            lowerCase[ch] = 0;
        }

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            upperCase[ch] = 0;
        }

        for (auto& it : word) {
            if (isupper(it)) {
                upperCase[it]++;
            } else {
                lowerCase[it]++;
            }
        }
        int count=0;
        for (int i = 0; i < 26; i++) {
            char lower = 'a' + i;
            char upper = 'A' + i;

            if(lowerCase[lower]>0 && upperCase[upper]>0){
                count++;
            }
        }

        return count;
    }
};