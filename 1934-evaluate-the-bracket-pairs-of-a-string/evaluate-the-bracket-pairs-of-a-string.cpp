class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto &it:knowledge){
            mpp[it[0]]=it[1];
        }
        int n=s.size();
        string ans="";
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ans+=temp;
                temp="";
            }
            else if(s[i]==')'){
                if(mpp.find(temp)!=mpp.end()){
                    ans+=mpp[temp];
                }
                else{
                    ans.push_back('?');
                }
                temp="";
            }
            else{
                temp.push_back(s[i]);
            }
        }

        if(temp.size()>0){
            ans+=temp;
        }

        return ans;
    }
};