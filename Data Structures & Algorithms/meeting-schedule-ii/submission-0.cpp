/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(auto c: intervals) {
            mp[c.start]++;
            mp[c.end]--;
        }

        int prev = 0;
        int mx = 0;
        for(auto x: mp) {
            prev += x.second;
            mx = max(mx,prev);
        }
        return mx;
    }
};
