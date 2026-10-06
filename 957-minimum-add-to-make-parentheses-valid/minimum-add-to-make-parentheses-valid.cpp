class Solution {
public:
    int minAddToMakeValid(string s) {
        int required = 0;
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                total++;
            } else {
                total--;
            }

            if (total < 0) {
                required++;
                total = 0;
            }
        }

        if(total>0){
            required+=total;
        }
        return required;
    }
};