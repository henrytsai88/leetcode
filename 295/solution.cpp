class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    bool isEven = true;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (isEven) {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
        isEven = !isEven;
    }
    
    double findMedian() {
        if (isEven) return (double) (small.top() + large.top()) / 2;
        return large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */