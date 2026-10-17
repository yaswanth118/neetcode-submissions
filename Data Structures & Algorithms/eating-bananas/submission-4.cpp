class Solution {
   public:
    bool possible(const vector<int>& p, long long k, long long h) {
        long long cnt = 0;
        for (auto x : p) {
            cnt += (x + k - 1) / k;
        }
        if (cnt <= h) {
            return true;
        } else {
            return false;
        }
    }

    int minEatingSpeed(vector<int>& p, int h) {
        long long l = 0, r = INT_MAX;
        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (possible(p, mid, h)) {
                r = mid;
            } else {
                l = mid;
            }
            cout << mid << endl;
        }
        return r;
    }
};
