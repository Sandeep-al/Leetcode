class Solution {
public:
    string trimTrailingVowels(string s) {
        
        int n=s.size()-1;
        while(n>=0){
            if(s[n]!='a' && s[n]!='e' && s[n]!='i' && s[n]!='o' && s[n]!='u'){
                break;
            }
            s.pop_back();
            n--;
        }

        return s;
       
    }
};