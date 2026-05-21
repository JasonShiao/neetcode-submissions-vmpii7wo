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

        // Method 1: acquire 10 tweets from each followee / user himself
        // pair: {time, tweetId}
        // priority_queue<pair<int, int>> max_heap; // larger timestamp -> more recent

        // // extract at most 10 tweets from each followee / user himself
        // int i = 10;
        // for (auto rit = tweets[userId].rbegin(); rit != tweets[userId].rend(); rit++) {
        //     if (i == 0) {
        //         break;
        //     }
        //     max_heap.push(*rit);
        //     i -= 1;
        // }
        // for (int followeeId : followees[userId]) {
        //     int i = 10;
        //     for (auto rit = tweets[followeeId].rbegin(); rit != tweets[followeeId].rend(); rit++) {
        //         if (i == 0) {
        //             break;
        //         }
        //         max_heap.push(*rit);
        //         i -= 1;
        //     }
        // }

        vector<int> res;
        // i = 0;
        // while (!max_heap.empty() && i < 10) {
        //     res.push_back(max_heap.top().second);
        //     max_heap.pop();
        //     i += 1;
        // }

        // Method 2: Extract one tweet from each followee, and then push next if needed
        priority_queue<tuple<int, int, int, int>> max_heap; // {time, tweetId, followeeId, next_tweet_index_for_user}
        for (int followeeId: followees[userId]) {
            if (tweets.find(followeeId) != tweets.end()) { // user exists 
                auto followee_tweets = tweets[followeeId];
                if (followee_tweets.size() > 0) {
                    int index = followee_tweets.size() - 1;
                    max_heap.push(make_tuple(followee_tweets[index].first, 
                                            followee_tweets[index].second,
                                            followeeId,
                                            index - 1));
                }
            }
        }
        // remember to include the user himself
        if (tweets.find(userId) != tweets.end()) { // user exists 
            auto user_tweets = tweets[userId];
            if (user_tweets.size() > 0) {
                int index = user_tweets.size() - 1;
                max_heap.push(make_tuple(user_tweets[index].first, 
                                        user_tweets[index].second,
                                        userId,
                                        index - 1));
            }
        }

        int count = 10;
        while (!max_heap.empty() && count > 0) {
            auto tup = max_heap.top(); // {time, tweetId, followeeId, next_tweet_index_for_user}
            res.push_back(get<1>(tup));
            max_heap.pop();
            if (get<3>(tup) >= 0) {
                auto tmp_tweet = tweets[get<2>(tup)][get<3>(tup)];
                max_heap.push(make_tuple(tmp_tweet.first, 
                                        tmp_tweet.second, 
                                        get<2>(tup), 
                                        get<3>(tup) - 1));
            }
            count--;
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
