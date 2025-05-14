constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int lengthAfterTransformations(string& s, int t) {
        int cnt[26] = {}, res = s.size(), z = 25;
        for (char c : s) cnt[c - 'a']++;
        while (t--) {
            res = (res + cnt[z]) % MOD;
            cnt[(z + 1) % 26] = (cnt[(z + 1) % 26] + cnt[z]) % MOD;
            z = (z + 25) % 26;
        }return res;
    }
};
