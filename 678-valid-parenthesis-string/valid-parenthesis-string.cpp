class Solution {
public:
    int dp[102][101];
    string s;
    int n;
    bool check(int score,int idx){

        if(score<0) return dp[score+1][idx]=0;

        if(idx==n) return dp[score+1][idx]=(score==0);
        if(dp[score+1][idx]!=-1){
            return dp[score+1][idx];
        }
        int ans1=0;
        if(s[idx]=='('){
            ans1=ans1 || check(score+1,idx+1);
        }
        else if(s[idx]==')'){
            ans1=ans1 || check(score-1,idx+1);
        }
        else{
            ans1=ans1 || check(score-1,idx+1);
            ans1=ans1 || check(score+1,idx+1);
            ans1=ans1 || check(score,idx+1);
        
        }

        return dp[score+1][idx]=ans1;
    }
    bool checkValidString(string s) {
        n=s.size();
        this->s=s;
        memset(dp,-1,sizeof(dp));

        return check(0,0);
    }
};