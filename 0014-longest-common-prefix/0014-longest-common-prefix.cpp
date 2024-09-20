class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string f = strs[0];
        string l = strs[n-1];
        string ans = "";
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == l[i]) {
                ans += f[i];
            } else {
                break;
            }
        }

        return ans;
    }
};