/* https://codeforces.com/contest/888/problem/D */

#include <iostream>
#include <vector>

using namespace std;

// Function to compute factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to compute derangements D(x)
long long derangement(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    
    long long D[x + 1];
    D[0] = 1;
    D[1] = 0;
    
    for (int i = 2; i <= x; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
    }
    
    return D[x];
}

// Function to compute binomial coefficient C(n, x)
long long binomial(int n, int x) {
    if (x > n) return 0;
    
    long long result = 1;
    for (int i = 1; i <= x; i++) {
        result *= n - i + 1;
        result /= i;
    }
    
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    long long total = 0;
    
    // Sum over all possible number of deranged elements (x from 0 to k)
    for (int x = 0; x <= k; x++) {
        total += binomial(n, x) * derangement(x);
    }
    
    cout << total << endl;
    
    return 0;
}
