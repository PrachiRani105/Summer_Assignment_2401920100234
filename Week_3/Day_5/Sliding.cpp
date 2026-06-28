auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

static int q_buffer[100005];

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        
        std::vector<int> result(n - k + 1);
        int result_idx = 0;
        
        int head = 0;
        int tail = 0; 
        
        for (int i = 0; i < n; ++i) {
           
            if (head < tail && q_buffer[head] < i - k + 1) {
                head++;
            }
            
            
            while (head < tail && nums[q_buffer[tail - 1]] < nums[i]) {
                tail--;
            }
            
            
            q_buffer[tail++] = i;
            
            
            if (i >= k - 1) {
                result[result_idx++] = nums[q_buffer[head]];
            }
        }
        
        return result;
    }
};