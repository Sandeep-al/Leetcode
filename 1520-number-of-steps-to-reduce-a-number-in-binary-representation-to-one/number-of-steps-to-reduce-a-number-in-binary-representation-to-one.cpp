class Solution {
public:
    void addone(string& s) {
        int x = s.size()-1;
        int carry = 1;
        while (x >= 0) {
            if (carry == 0)
                break;
            if (s[x] == '1') {

                s[x] = '0';
                carry = 1;
            }
            else if (s[x] == '0') {

                s[x] = '1';
                carry = 0;
            }
            x--;
        }

        if (carry == 1) {
            s = '1' + s;
        }

        return;
    }

    void divide(string& s) {

        s.pop_back();

        return;
    }

    
    int numSteps(string s) {

        int count=0;
        while(s!="1"){

            int n=s.size()-1;
            if(s[n]=='0'){
                divide(s);
            }

            else{
                addone(s);
            }

            count++;
        }

        return count;
    }
};