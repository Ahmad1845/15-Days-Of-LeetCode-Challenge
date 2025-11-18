class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[256]; 
        for (int i = 0; i < 256; i++) 
            lastIndex[i] = -1;   // store last seen positions

        int maxLen = 0;
        int start = 0; // left pointer

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // if character seen before and inside current window
            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1; // move left pointer
            }

            lastIndex[c] = i; // update last seen index
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
