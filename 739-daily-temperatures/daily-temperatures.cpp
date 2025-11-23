class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;  // stores indices of days

        for (int i = 0; i < n; i++) {
            // While current temp is hotter than the top of stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx; // days waited
            }
            st.push(i);
        }

        return answer;
    }
};
