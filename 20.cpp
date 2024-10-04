class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
                continue;
            }
            if (i == ']') {
                if (st.empty() || st.top() != '[') {
                    return 0;
                }
                st.pop();
                continue;
            }
            if (i == ')') {
                 if (st.empty() || st.top() != '(') {
                    return 0;
                }
                st.pop();
                continue;
            }
            if (i == '}') {
                 if (st.empty() || st.top() != '{') {
                    return 0;
                }
                st.pop();
                continue;
            }
        }

        return st.empty();
    }
};
