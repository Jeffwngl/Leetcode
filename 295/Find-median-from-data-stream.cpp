class MedianFinder {
private:
    // maxHeap will always have median
    priority_queue<int, vector<int>, greater<int>>minHeap{}; // upper arr
    priority_queue<int>maxHeap{}; // lower arr
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        // always push to maxHeap first
        maxHeap.push(num);

        // ensure ordering: maxHeap.top() <= minHeap.top()
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // rebalance sizes (maxHeap can have 1 extra)
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2;
        }
        else return static_cast<double>(maxHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
