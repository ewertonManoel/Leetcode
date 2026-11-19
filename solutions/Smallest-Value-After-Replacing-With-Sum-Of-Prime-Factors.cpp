class Solution {
public:
    int smallestValue(int n) {
        vector<int> spf(n + 1, 0); for(int i = 2; i <= n; i++) spf[i] = i;
        for(int i = 2; i * i <= n; i++) {
            if(spf[i] != i) continue;
            for(int j = i * i; j <= n; j += i) if(spf[j] == j) spf[j] = i;
        }
        int cur = n;
        while(spf[cur] != cur) {
            int old = cur;
            int sum = 0;
            while(cur != 1) {
                sum += spf[cur];
                cur /= spf[cur];
            }
            cur = sum;
            if(old == cur) return cur;
        }
        return cur;
    }
};