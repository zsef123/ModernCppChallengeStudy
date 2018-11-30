#include <gsl/gsl>
#include <vector>


template <class T, class Container = std::vector<T>,
          class Compare = std::less<T> >
class PriorityQueue {
    private:
        Container c;
        Compare comp;
    
    public:
        explicit PriorityQueue(const Container& c_  = Container(),
                                const Compare& comp_ = Compare())
                                : c(c_), comp(comp_)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }
    
        bool empty() const { 
            return c.empty();
        }
        std::size_t size() const {
            return c.size();
        }
    
        const T& top() const {
            return c.front();
        }
    
        void push(const T& x) {
            c.push_back(x);
            std::push_heap(c.begin(), c.end(), comp);
        }
        
        void pop() {
            std::pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }
};



// Priorty Queue
int main(int argc, char* argv[])
{
    std::vector<int> v = {45,5,3,42,2,4};
    pr = PriorityQueue(v);
    for (int i = 0; i < pr.size(); i++) {
        printf("%d ", pr.pop());
    }
    return 0;
}
