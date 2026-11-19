int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = INT_MIN, smallest = INT_MAX;
        for(int i : nums) {
            largest = max(largest, i);
            smallest = min(smallest, i);
        }
        return gcd(largest, smallest);
    }
};