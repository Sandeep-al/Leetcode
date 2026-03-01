class Solution {
public:
    string trimTrailingVowels(string s) {
        
        int n=s.size()-1;
        while(n>=0){
            if(s[n]!='a' && s[n]!='e' && s[n]!='i' && s[n]!='o' && s[n]!='u'){
                break;
            }
            n--;
        }
        string x="";
        for(int i=0;i<=n;i++){
            x.push_back(s[i]);
        }

        return x;

        return x;
    }
};