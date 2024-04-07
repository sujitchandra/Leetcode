class Solution {
public:
    unsigned long long power(unsigned long long n, unsigned long long t) {
        if (t == 0) return 1;
        unsigned long long temp = power(n, t/2);
        if (t % 2 == 0)
            return (temp * temp) % 1000000007;
        else
            return (n * temp * temp) % 1000000007;
    }

    unsigned long long countGoodNumbers(unsigned long long n) {
        unsigned long long even = (n + 1) / 2;
        unsigned long long prime = n / 2;
        unsigned long long first = power(5, even) % 1000000007;
        unsigned long long second = power(4, prime) % 1000000007;
        return (first * second) % 1000000007;
    }
};