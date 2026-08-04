class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0; 
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false; 
        int number = 0;
        for(int i = 2; i * i < n; i++) {
            if(!primes[i]) continue;
            for(int j = i * i; j < n; j += i) primes[j] = false;
        }
        for(bool b : primes) if(b) number++;
        return number;
    }
};