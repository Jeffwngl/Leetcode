class EventManager {
private:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first) return a.first > b.first; // largest priority first
            return a.second < b.second; // smallest id first if priorities equal
        }
    };
public:
    set<pair<int, int>, cmp>s;
    unordered_map<int, int>mp;
    EventManager(vector<vector<int>>& events) {
        int n = events.size();
        for (int i = 0; i < n; ++i) {
            s.insert({events[i][1], events[i][0]});
            mp[events[i][0]] = events[i][1];
            // cout << "as" << endl;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (mp.count(eventId)) {
            // remove old value
            auto it = s.find({mp[eventId], eventId});
            if (it != s.end()) s.erase(it);
        }
        mp[eventId] = newPriority;
        s.insert({newPriority, eventId});
    }
    
    int pollHighest() {
        if (s.empty()) return -1;
        auto it = s.begin();
        int id = it->second;
        s.erase(it);
        // cout << " asdas" << endl;
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
