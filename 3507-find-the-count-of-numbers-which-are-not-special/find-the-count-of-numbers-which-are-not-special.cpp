class Solution {
public:
    // 10, 12
    int getsqrt(int n) {
        if(n==1||n==2||n==3) return 1;
        int ans = 0;
        for(int i=2;i<=n/2;i++){
            if(i*i<=n){
                ans = i;
            }
        }
        return ans;
    }
    bool isPrime(int n) {
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
        cout<<strt<<" "<<end<<endl;
        int ans = 0;
        //4,16
        // 2,4
        if(strt !=1){
        if(strt*strt == l && isPrime(strt)) ans++;
        }
        if(end!=1){
        if(end*end <=r && end*end>l && isPrime(end)){ 
            cout<<"fd"<<endl;
            ans++;} 
        }
        
        for(int i=strt+1;i<end;i++){
            cout<<i<<endl;
            if(isPrime(i)) ans++;
        }
        cout<<ans<<endl;
        return (r-l+1) - (ans);
    }
};