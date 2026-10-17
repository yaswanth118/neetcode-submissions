class Solution {
   public:
    int find_min(vector<int>& v) {
        int n = v.size();
        if (v[0] < v[n - 1]) {
            return 0;
        }

        // you're finding r where it's min
        int l = -1, r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (v[mid] > v[n - 1]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }

    int search(vector<int>& v, int target) {
        int n = v.size();
        int x = find_min(v);
        int l = -1, r = n;
        if (x == 0) {
            l = -1;
            r = n;
        } else {
            if (target >= v[0]) {
                l = -1;
                r = x;
            } else {
                l = x;
                r = n;
            }
        }

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (v[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == -1) {
            return -1;
        } else {
            if (v[l] == target) {
                return l;
            } else {
                return -1;
            }
        }
    }
};
