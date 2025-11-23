class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // If opening bracket → push
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If closing bracket but stack empty → invalid
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Valid only if stack becomes empty
        return st.empty();
    }
};
