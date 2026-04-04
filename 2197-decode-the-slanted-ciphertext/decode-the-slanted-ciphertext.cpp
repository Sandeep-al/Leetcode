class Solution {
public:
    
    string decodeCiphertext(string encodedText, int rows) {
        int columns=encodedText.size()/rows;
        int n=encodedText.size();
        string real_ans="";
        for(int i=0;i<columns;i++){
            
            for(int j=i;j<n;j=j+columns+1){
                real_ans.push_back(encodedText[j]);
            }

        }
        real_ans.erase(real_ans.find_last_not_of(' ') + 1);


        return real_ans;
    }
};