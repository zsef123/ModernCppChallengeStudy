#include <gsl/gsl>
#include <vector>
#include <iostream>
// Circular buffer

template <typename T>
class CircularBuffer {
    private:
    int capacity;
    std::vector<int> vec;
    int current_idx;
    int current_size;

    public:
    CircularBuffer(const int capacity=3)
    : capacity(capacity), current_idx(0), current_size(0)
    {
        vec(size);
    }

    void push(const T& x) {
        vec[current_idx++] = x;
        if (current_size < capacity)
            current_size++;
        if (current_idx == capacity) {
            current_idx = 0;
        }
    }

    void pop() {
        current_size--;
        current_idx--;        
    }

    bool empty() {        
        return (current_size == 0);
    }

    bool full() {
        return (current_size == size);
    }

    int size() {
        return size;
    }

    int capacity() {
        return capacity;
    }

    void print_all() {
        std::cout << vec << "\n";
    }
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1,2,3,4,5,6};
    CircularBuffer<int> cb(3);
    for (auto v : vec) {
        cb.push(v);
        cv.print_all();
    }

    return 0;
}
