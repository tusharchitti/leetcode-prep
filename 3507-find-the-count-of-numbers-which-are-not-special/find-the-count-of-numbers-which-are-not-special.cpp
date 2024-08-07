class Solution {
public:
    bool isPrime(int n) {
        if(n == 1) return false;
        if(n ==1 || n== 2 || n==3||n==5) return true;
        if(n == 4) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int strt = sqrt(l);
        int end = sqrt(r);
        int ans = 0;
        if(strt*strt<l) strt++;
        if(end*end>=l){
            for(int i = strt;i<=end;i++){
                if(isPrime(i)) ans++;
            }
        }
        return (r-l+1) - (ans);
    }
};