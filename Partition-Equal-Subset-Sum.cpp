vector<vector<int>> memo;

bool knapsack(int i, int cap, vector<int>& w) {
    if(cap == 0) return true;
    if(cap < 0) return false;
    if(i == w.size()) return false;
    if(memo[i][cap] != -1) return memo[i][cap];
    bool skip = knapsack(i + 1, cap, w);
    bool take = knapsack(i + 1, cap - w[i], w);
    return memo[i][cap] = skip || take;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        if(sum & 1) return false;
        int cap = sum / 2;
        memo.assign(nums.size() + 1, vector<int>(cap + 1, -1));
        return knapsack(0, cap, nums);
    }
};