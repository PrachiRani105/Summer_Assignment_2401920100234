auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class RecentCounter {
private:
    int buffer[3005]; 
    int head;         
    int tail;        

public:
    RecentCounter() {
        head = 0;
        tail = 0;
    }
    
    int ping(int t) {
        buffer[tail] = t;
        tail = (tail + 1) % 3005;
        
        int min_time = t - 3000;
        while (buffer[head] < min_time) {
            head = (head + 1) % 3005;
        }
        if (tail >= head) {
            return tail - head;
        } else {
            return (3005 - head) + tail;
        }
    }
};