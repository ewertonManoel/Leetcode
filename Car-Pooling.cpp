class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int sz = 1005; int passengers[sz]; memset(passengers, 0, sizeof(passengers));
        for(auto& info : trips) {
            passengers[info[1]] += info[0];
            passengers[info[2]] -= info[0];
        }
        if(passengers[0] > capacity) return false;
        for(int i = 1; i < sz; i++) {
            passengers[i] += passengers[i-1];
            if(passengers[i] > capacity) return false;
        }
        return true;
    }
};