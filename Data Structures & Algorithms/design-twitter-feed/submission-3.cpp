class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> followees;  // user, [followee1, ...]
    unordered_map<int, vector<pair<int, int>>> tweets; // user, [{time, tweet_id}, ..]
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time += 1; // used to sort the tweet chronologically
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Notice: also include the tweets from user himself!!
        // pair: {time, tweetId}
        priority_queue<pair<int, int>> max_heap; // larger timestamp -> more recent

        // extract at most 10 tweets from each followee / user himself
        int i = 10;
        for (auto rit = tweets[userId].rbegin(); rit != tweets[userId].rend(); rit++) {
            if (i == 0) {
                break;
            }
            max_heap.push(*rit);
            i -= 1;
        }
        for (int followeeId : followees[userId]) {
            int i = 10;
            for (auto rit = tweets[followeeId].rbegin(); rit != tweets[followeeId].rend(); rit++) {
                if (i == 0) {
                    break;
                }
                max_heap.push(*rit);
                i -= 1;
            }
        }

        vector<int> res;
        i = 0;
        while (!max_heap.empty() && i < 10) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
            i += 1;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].erase(followeeId);
    }
};
