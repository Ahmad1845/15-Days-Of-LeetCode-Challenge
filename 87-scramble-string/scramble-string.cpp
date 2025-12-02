class Solution {
public:
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {
        string key = s1 + "_" + s2;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            bool noSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                          isScramble(s1.substr(i), s2.substr(i));
            
            if (noSwap) {
                return mp[key] = true;
            }

            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                        isScramble(s1.substr(i), s2.substr(0, n - i));
            
            if (swap) {
                return mp[key] = true;
            }
        }

        return mp[key] = false;
    }
};