long long binary_exponentiation(long long x, long long y, long long M){  // x pow y
    long long ans=1;
    while(y){
        if(y&1){        // checking whether the right most bit is 1 or not
            ans*=x; 
            ans%=M;   // 1e9 + 7
        }
        x*=x; x%=M;
        y>>=1;          // rightt shift (a>>b == a divided by (2 pow b) )
    }
    return ans%M;
}