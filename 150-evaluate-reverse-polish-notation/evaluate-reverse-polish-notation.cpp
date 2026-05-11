class Solution {
public:
    int convert(string s) {

        int sign = 1;
        int i = 0;
        long long num = 0;

        if (s[0] == '-') {
            sign = -1;
            i = 1;
        }

        while (i < s.size()) {

            num = num * 10 + (s[i] - '0');

            i++;
        }

        return num * sign;
    }

    string convert_back(long long num) {

        // special case
        if (num == 0)
            return "0";

        string ans = "";

        bool negative = false;

        if (num < 0) {
            negative = true;
            num = -num;
        }

        while (num > 0) {

            int digit = num % 10;

            ans.push_back(digit + '0');

            num /= 10;
        }

        reverse(ans.begin(), ans.end());

        if (negative) {
            ans = "-" + ans;
        }

        return ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto& it : tokens) {
            if (it != "+" && it != "-" && it != "*" && it != "/") {
                st.push(it);
            } else {
                long long second = convert(st.top())  ;
                st.pop();
                long long first = convert(st.top());
                st.pop();
                long long ans = 0;
                if (it == "+") {
                    ans = first + second;
                } else if (it == "-") {
                    ans = first - second;
                } else if (it == "*") {
                    ans = first * second;
                } else {
                    ans = first / second;
                }
                st.push(convert_back(ans));
            }
        }

        return convert(st.top());
    }
};