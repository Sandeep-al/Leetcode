class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int count = 0;
        int l = 0;
        int mini = INT_MAX;
        string smallest="";
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '1')
                count++;

            while (count > k) {
                if (s[l] == '1')
                    count--;
                l++;
            }

            if (count == k) {
                while (s[l] == '0')
                    l++;


                if (i - l + 1 < mini) {
                    mini = i - l + 1;
                    smallest = s.substr(l, i - l + 1);
                } else if ((i - l + 1) == mini) {
                    string temp = s.substr(l, i - l + 1);
                    if (temp < smallest) {
                        smallest = temp;
                    }
                }
            }
        }

        
        return smallest;
    }
};