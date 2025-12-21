class Solution {
public:
    vector<string> temp;
    vector<string> final_ans;
    int n;

    bool isvalid(string& y, int start, int end) {
        int len = end - start + 1;
        
        // 1. Length > 3 nahi honi chahiye (waise loop sambhal raha hai, but safety)
        if (len > 3) return false;

        // 2. Leading Zero Check: "0" allowed hai, par "01", "00" nahi
        if (y[start] == '0' && len > 1) return false;

        // 3. Value > 255 Check
        // Note: stoi ke liye string extract karni padegi
        long long val = stoll(y.substr(start, len)); 
        if (val > 255) return false;

        return true;
    }

    void compute(int i, string& s) {
        
        if (i == n) {
           
            if (temp.size() == 4) {
                string x = "";
                for (int k = 0; k < temp.size(); k++) {
                    x += temp[k];
                    if (k < temp.size() - 1) x += ".";
                }
                final_ans.push_back(x);
            }
            return;
        }
        
       
        if (temp.size() >= 4) return;

       
        for (int j = i; j < min(i + 3, n); j++) {
            
            
            if (isvalid(s, i, j)) {
                
                
                temp.push_back(s.substr(i, j - i + 1));
                
                compute(j + 1, s);
                
                temp.pop_back(); 
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();
       
        if (n > 12) return {}; 
        compute(0, s);
        return final_ans;
    }
};