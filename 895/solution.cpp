class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxFreq = 0;
public:
    FreqStack() {}
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int val = m[maxFreq].top(); m[maxFreq].pop();
        if (m[freq[val]--].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */