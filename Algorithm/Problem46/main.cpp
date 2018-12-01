#include <gsl/gsl>
#include <vector>
#include <iostream>
// Circular buffer

template <typename T>
class CircularBuffer {
    private:
    std::vector<int> vec;
    int current_idx;
    int current_size;

    public:
    CircularBuffer(const int capacity_=3)
    : current_idx(0), current_size(0), vec(capacity_, 0)
    { }

    void push(const T& x) {
        vec[current_idx] = x;
        current_idx++;
        if (current_size < vec.size())
            current_size++;
        if (current_idx == vec.size())
            current_idx = 0;
    }

    // empty를 고쳐 안했구나
    void pop() {
        current_size--;
        current_idx--;
    }

    bool empty() {
        return (current_size == 0);
    }

    bool full() {
        return (current_size == vec.size());
    }

    int size() {
        return current_size;
    }

    int capacity() {
        return vec.size();
    }

    void print_all() {
        int start = current_idx-1;
        std::cout << "current_size : " << current_size << ", current_idx : " << current_idx << "\n";
        for (int i = 0 ; i < current_size; i++) {
            std::cout << vec[start++];
            if (start == current_size)
                start = 0;
        }
        std::cout << "\n";
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1,2,3,4,5,6};
    CircularBuffer<int> cb(3);
    for (auto v : vec) {
        cb.push(v);
        cb.print_all();
    }

    return 0;
}
