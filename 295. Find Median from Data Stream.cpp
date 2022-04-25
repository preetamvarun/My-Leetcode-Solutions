class MedianFinder {
public:
    priority_queue<double>max_heap;
    priority_queue<double,vector<double>,greater<double>>min_heap;
    
    void addNum(int num) {
        if(max_heap.size() == 0 || max_heap.top() >= num){
            max_heap.push(num);
        } else{
            min_heap.push(num);
        }
        // BALANCE BOTH THE HEAPS
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > max_heap.size() + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == 0 && max_heap.size() == 1){
            return max_heap.top();
        }
        else if(max_heap.size() == min_heap.size()){
            return (max_heap.top() + min_heap.top())/2;
        }
        else if(max_heap.size() > min_heap.size()){
            return max_heap.top();
        }
        else{
            return min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
