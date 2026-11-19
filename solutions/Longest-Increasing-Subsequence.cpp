class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int i : nums) {
            if(tails.empty() || i > tails.back()) tails.push_back(i);
            else tails[lower_bound(tails.begin(), tails.end(), i) - tails.begin()] = i;
        }
        return tails.size();
    }
};