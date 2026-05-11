class Solution {
public:

    string minRemoveToMakeValid(string s) {

        string temp = "";

        int open = 0;

        // pass 1 -> remove invalid ')'
        for(char ch : s){

            if(ch == '('){

                open++;
                temp.push_back(ch);
            }

            else if(ch == ')'){

                if(open > 0){

                    open--;
                    temp.push_back(ch);
                }
            }

            else{
                temp.push_back(ch);
            }
        }

        string ans = "";

        int close = 0;

        // pass 2 -> remove extra '('
        for(int i=temp.size()-1; i>=0; i--){

            char ch = temp[i];

            if(ch == ')'){

                close++;
                ans.push_back(ch);
            }

            else if(ch == '('){

                if(close > 0){

                    close--;
                    ans.push_back(ch);
                }
            }

            else{
                ans.push_back(ch);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};