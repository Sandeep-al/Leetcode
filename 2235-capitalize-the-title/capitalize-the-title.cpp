class Solution {
public:
    void solve(string& x) {

        int n = x.size();

        if(n<3){
            for(int i=0;i<n;i++){
                x[i]=tolower(x[i]);
            }
            return ;
        }
        x[0] = toupper(x[0]);

        for (int i = 1; i < n; i++) {
            if (isupper(x[i])) {
                x[i] = tolower(x[i]);
            }
        }
    }
    string capitalizeTitle(string title) {
        string x = "";
        string final_ans = "";
        for (int i = 0; i < title.size(); i++) {
            if (title[i] == ' ') {
                solve(x);
                final_ans += x;
                final_ans += ' ';
                x = "";
            } else {
                x += title[i];
            }
        }

        if (x.size() > 0) {
            solve(x);
            final_ans += x;
        }

        return final_ans;
    }
};