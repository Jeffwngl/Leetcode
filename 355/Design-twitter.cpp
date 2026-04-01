class Twitter {
private:
    struct Post {
        int userId{};
        int tweetId{};
        int timePosted{};

        bool operator<(const Post& other) const { // overload operator for pq to compare by this instead
            return timePosted < other.timePosted;
        }
    };

    struct UserData {
        set<int>m_following;
        vector<Post>m_posts;
    };

    // userId, posts
    unordered_map<int, UserData>users{};

    int time{};

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Post post {userId, tweetId, time};
        users[userId].m_posts.push_back(post);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Post>pq;
        // push following users posts
        for (auto& p : users[userId].m_following) {
            for (auto& post : users[p].m_posts) {
                pq.push(post);
            }
        }
        // push own posts
        for (auto& post : users[userId].m_posts) pq.push(post);

        vector<int>newsFeed;
        while (!pq.empty() && newsFeed.size() < 10) {
            auto tId = pq.top().tweetId;
            pq.pop();
            newsFeed.push_back(tId);
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users[followerId].m_following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].m_following.erase(followeeId);
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
