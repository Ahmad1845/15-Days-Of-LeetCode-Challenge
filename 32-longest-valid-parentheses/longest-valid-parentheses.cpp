class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // initialize with a base index
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // store index of open parenthesis
            } else {
                st.pop(); // match the current ')'
                
                if (st.empty()) {
                   
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};