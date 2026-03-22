class MyCircularQueue {
public:
    vector<int> v;
    int tail = -1;
    int head = 0;
    int max_size;
    int cur_size = 0;
    MyCircularQueue(int k) {
        v.assign(k, 0);
        max_size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail + 1) % max_size;
        v[tail] = value;
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if(cur_size <= 0) return false;
        head = (head + 1) % max_size;
        cur_size--;
        return true;
    }
    
    int Front() {
        if (cur_size)
            return v[head];
        else
            return -1;
    }
    
    int Rear() {
        if (cur_size)
            return v[tail];
        else
            return -1;
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
}; 

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */