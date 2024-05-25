class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // There are no primes less than 2

        vector<int> primes(n, 1); // Vector initialized with 1s
        primes[0] = primes[1] = 0; // 0 and 1 are not prime numbers

        for (int i = 2; i * i < n; i++) {
            if (primes[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0; // Mark multiples of i as non-prime
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i] == 1) {
                count++;
            }
        }
        return count;
    }
};
// using sieve algorithm..
