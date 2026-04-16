class TimeMap {
public:
    unordered_map<string, vector<tuple<int, string>>> hash_map;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (hash_map.find(key) == hash_map.end()) {
            // create new vector
            hash_map[key] = vector<tuple<int, string>>();
        }
        hash_map[key].push_back(make_tuple(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        // binary search
        if (hash_map.find(key) == hash_map.end()) {
            return "";
        }

        int left = 0;
        int right = hash_map[key].size() - 1;
        auto &vec_ref = hash_map[key];
        while (left < (right-1)) {
            int half = (left + right) / 2;

            if (get<0>(vec_ref[half]) == timestamp) {
                return get<1>(vec_ref[half]);
            } else if (get<0>(vec_ref[half]) < timestamp) {
                left = half;
            } else {
                right = half - 1;
            }
        }

        if (get<0>(vec_ref[right]) <= timestamp) {
            return get<1>(vec_ref[right]);
        } else if (get<0>(vec_ref[left]) <= timestamp) {
            return get<1>(vec_ref[left]);
        }

        return "";
    }
};
