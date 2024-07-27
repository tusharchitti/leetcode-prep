class Solution {
public:
    int minChanges(int n, int k) {
        if(n==k) return 0;
        int m = n^k;
        if(((m)&k) !=0) {
            return -1;
        }
        int rem = ((m)&n);
        int ans=0;
        while(rem){
           if(rem%2 == 1) ans++;
           rem = rem/2;
        }
        return ans; 
    }
};