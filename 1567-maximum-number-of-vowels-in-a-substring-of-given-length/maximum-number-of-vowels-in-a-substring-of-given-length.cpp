class Solution {
public:
    bool vowel(char c){

        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return 1;
        }

        return 0;
    }
    int maxVowels(string s, int k) {
        int count=0;
        int sum=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(vowel(s[i])){
                sum++;
            }


            if(i>=k){
                if(vowel(s[i-k])){
                    sum--;
                }
            }

            if(i>=k-1){
                count=max(count,sum);
            }
        }

        return count;
    }
};