class Solution {
   public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty())return false;
                char x = st.top();
                if ((s[i] == ')' && x == '(') || (s[i] == ']' && x == '[') ||
                    (s[i] == '}' && x == '{')) {
                        st.pop();
                } else {
                    return false;
                }
            }
        }
        if(!st.empty())return false;
        return true;
    }
};
