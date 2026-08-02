int lcs_size[1005][1005];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string& s = text1; string& t = text2;
        int n = s.size(); int m = t.size();
        memset(lcs_size, 0, sizeof(lcs_size));
        for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
            if(s[i] == t[j]) lcs_size[i][j] = 1 + lcs_size[i+1][j+1];
            else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
        }
        return lcs_size[0][0];
    }
};