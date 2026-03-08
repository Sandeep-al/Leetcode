class Solution {
public:
    unordered_set<string> ans;
    vector<string> store;
    int len;
    void solve(int i, string& yo) {
        if (i == len) {
            store.push_back(yo);
            return;
        }

        yo.push_back('1');
        solve(i + 1, yo);
        yo.pop_back();
        yo.push_back('0');
        solve(i + 1, yo);
        yo.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {

        len = nums.size();
        string yo = "";
        for (auto& it : nums) {
            ans.insert(it);
        }
        solve(0,yo);
        for (auto& it : store) {
            if (!(ans.count(it))) {
                return it;
            }
        }

        return "";
    }
};