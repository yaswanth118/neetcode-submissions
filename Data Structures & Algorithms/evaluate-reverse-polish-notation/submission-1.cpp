class Solution {
   public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for (auto x : t) {
            if (x == "+" || x == "*" || x == "-" || x == "/") {
                int x1 = s.top();
                s.pop();
                int x2 = s.top();
                s.pop();
                if (x == "+") {
                    s.push(x1 + x2);
                } else if (x == "*") {
                    s.push(x1 * x2);
                } else if (x == "-") {
                    s.push(x2 - x1);
                } else if (x == "/") {
                    s.push(x2 / x1);
                }
            } else {
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};
