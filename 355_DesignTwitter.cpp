// Time : Beats 73.97%
// Memory : Beats 40.66%
class Twitter {
public:
	// post list with time/content
	typedef pair<unsigned int, int> PostTy;
	typedef list<PostTy> PostsTy;
	// user post dict
	map<int , PostsTy> PostMap;
	// follower/followee map
	map<int , set<int>> FollowMap;

	unsigned int postTime;

	Twitter() : postTime(0) {
	}

	void postTweet(int userId, int tweetId) {
		PostMap[userId].push_back({postTime, tweetId});
		if (PostMap[userId].size() > 10) {
			PostMap[userId].pop_front();
		}
		++postTime;
	}

	vector<int> getNewsFeed(int userId) {
		// I am a follower of me
		this->follow(userId, userId);

		priority_queue<PostTy> maxheap;
		// heap sort the follower queues
		for (auto followee : FollowMap[userId]) {
			for (PostTy& post : PostMap[followee]) {
				maxheap.push(post);
			}
		}

		vector<int> posts;
		for (int i=0; i<10; ++i) {
			if (maxheap.empty()) break;
			posts.push_back(maxheap.top().second);
			maxheap.pop();
		}
		return posts;
	}

	void follow(int followerId, int followeeId) {
		FollowMap[followerId].insert(followeeId);
	}
	void unfollow(int followerId, int followeeId) {
		FollowMap[followerId].erase(followeeId);
	}
