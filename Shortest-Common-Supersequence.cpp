#define s (*ptrs)
#define t (*ptrt)
string *ptrs, *ptrt;
int lcs_size[1005][1005];
string lcs; int n, m;
void lcs_build(int i = 0, int j = 0) {
    if(i >= n || j >= m) return;
    if(s[i] == t[j]) {
        lcs += s[i];
        lcs_build(i + 1, j + 1);
    }
    else if(lcs_size[i+1][j] >= lcs_size[i][j+1]) lcs_build(i+1, j);
    else lcs_build(i, j+1);
}
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ptrs = &str1; ptrt = &str2;
        n = s.size(); m = t.size();
        memset(lcs_size, 0, sizeof(lcs_size)); lcs = "";
        for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
            if(s[i] == t[j]) lcs_size[i][j] = 1 + lcs_size[i+1][j+1];
            else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
        }
        lcs_build();
        int i = 0, j = 0;
        string scs;
        for(char c : lcs) {
            while(i < n && c != s[i]) {
                scs += s[i];
                i++;
            }
            while(j < m && c != t[j]) {
                scs += t[j];
                j++;
            }
            scs += c;
            i++; j++;
        }
        for(; i < n; i++) scs += s[i];
        for(; j < m; j++) scs += t[j];
        return scs;
    }
};