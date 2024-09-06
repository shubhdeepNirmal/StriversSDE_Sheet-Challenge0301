#define mod 1000000007

class Solution {
public:
   long long power(long long x, long long n){
    if(n==0) return 1;
    if(n==1) return x;
    if(n%2){
        return (x* power(x,n-1))%mod;
    }
    return power((x*x)%mod,n/2);
   }
    int countGoodNumbers(long long n) {
       long long even= (n+1)/2;
       long long odd= n/2;

       long long a= power(5,even)%mod;
       long long b= power(4,odd)%mod;
       return (int)((a*b)%mod);  
    }
};