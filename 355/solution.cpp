class Twitter {
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int timestamp;
    struct compare {
        bool operator() (const auto& p, const auto& q) {
            return p.second > q.second;
        }
    };
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({tweetId, timestamp++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (pair<int, int> p : tweetMap[userId]) {
            pq.push(p);
            if (pq.size() > 10) pq.pop();
        }
        for (int followeeId : followMap[userId]) {
            for (pair<int, int> p : tweetMap[followeeId]) {
                pq.push(p);
                if (pq.size() > 10) pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().first); pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */