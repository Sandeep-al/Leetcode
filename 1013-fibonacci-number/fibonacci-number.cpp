class Solution {
public:
     unordered_map<int,int> m;
    int fib(int n) {
        if(n==1|n==0) return n;
        if(m.find(n)!=m.end()){
            return m[n];
        }
        else{
        m[n]= fib(n-1)+fib(n-2);
        return m[n];
        }
    }
};