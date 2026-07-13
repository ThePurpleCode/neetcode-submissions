class MyCircularQueue {
public:
    vector<int> data; // array to store values
    int head; // tracks in deque , holds oldest element so we can remove it
    int tail; // tracks in enqueue , tracks empty slot where new element can be placed
    int capacity; // size of this queue == k+1 .. k+1 due to apne ko diffentiate krna hai jb head==tail hoga toh queue empty bhi ho sakti hau and full bhi isi liye k+1; 
    MyCircularQueue(int k) {
        capacity = k+1;
        head=0;
        tail=0;
        data.resize(capacity);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false; //agr full hai toh add nhi kr skate
        // tail empty space starck kr rhi hai 
        data[tail] = value; // uss empty space mein value daal de
        tail = (tail+1)%capacity; // tail ko circular age bdha
        return true; // task successfull
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        // just head ko age bdha jo effectively elemetn ko remove karega
        head = (head+1)% capacity;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[head];
        
    }
    
    int Rear() {
        if(isEmpty()) return -1;

        return data[(tail-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        return head==tail; // agr dono pointers ek jagah hai toh empty hai 
    }
    
    bool isFull() {
        return (tail+1)% capacity == head; // agr head tail ke age hai in circle toh full hai
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