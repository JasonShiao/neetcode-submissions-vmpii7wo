class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // tips: start from the fleet (car) closer to the target

        // calc dist
        vector<tuple<int, int>> dist_speed_pairs;
        for (int i = 0; i < position.size(); i++) {
            dist_speed_pairs.push_back(make_tuple(target - position[i], speed[i]));
        }

        // sort by dist
        sort(dist_speed_pairs.begin(), dist_speed_pairs.end(), [](const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b);
        });

        int tail_fleet_idx = 0;
        double time2 = (double)get<0>(dist_speed_pairs[0]) / get<1>(dist_speed_pairs[0]);
        int fleet_cnt = 1;
        for (int i = 1; i < dist_speed_pairs.size(); i++) {
            double time1 = (double)get<0>(dist_speed_pairs[i]) / get<1>(dist_speed_pairs[i]);
            if (time1 > time2) {
                // new fleet (add count)
                fleet_cnt += 1;
                // update tail_fleet_idx
                tail_fleet_idx = i;
                // update time2
                time2 = time1;
            }
        }

        return fleet_cnt;
    }
};
