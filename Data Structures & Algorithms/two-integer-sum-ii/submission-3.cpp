class Solution {
   public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int rem = target - v[i];
            int l = -1, r = i;
            if (rem < v[i]) {
                l = -1;
                r = i;
            } else {
                l = i;
                r = n;
            }

            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (v[mid] <= rem) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (v[l] + v[i] == target) {
                return {min(i + 1, l + 1), max(i + 1, l + 1)};
            }
        }

    }
};
