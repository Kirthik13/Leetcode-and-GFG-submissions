class Twitter {
public:
    map<int,unordered_set<int>>userscon;
    deque<pair<int,int>>posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_front({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        for(auto &i:posts)
        {
            if(i.first==userId)
            {
                ans.push_back(i.second);
            }
            else if(userscon[userId].find(i.first)!=userscon[userId].end())
            {
                ans.push_back(i.second);

            }
            
            if(ans.size()==10) return ans;
            
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userscon[followerId].insert(followeeId);
        // usersfollowers[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userscon[followerId].erase(followeeId);
        // usersfollowers[followeeId].erase(followerId);        

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