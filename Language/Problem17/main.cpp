#include <gsl/gsl>
#include <memory>

template<typename T, size_t ROW, size_t COL>
class Array2D {
    private:
        std::unique_ptr<T[]>  storage;
        std::unique_ptr<T*[]> array;
        
    public:
        Array2D() :
            storage(std::make_unique<T[]>(ROW * COL)),
            array(std::make_unique<T*[]>(ROW)) 
        {
            for (size_t i = 0; i < ROW; i++)
                array[i] = &storage[i * COL];
        }

        Array2D(std::initializer_list<T> &&list) : Array2D()
        {
            // no existing like memcpy?
            int i = 0;
            for (auto t : list) 
                storage[i++] = t;
        }

        Array2D(std::initializer_list<std::initializer_list<T>> &&list) : Array2D()
        {
            int i = 0;
            for (auto j : list) {
                for (auto k : j)
                    storage[i++] = k;
            }
        }

        T* operator[](size_t row) {
            return array[row];
        }

        size_t size() {
            return ROW * COL;
        }

        T& at(size_t row, size_t col) {
            return storage[row * col + col];
        }

        T* data() {
            return storage.get();
        }

        T* begin() {
            return data();
        }
        T* end() {
            return &(storage[ROW * COL]);
        }


        // what different const T& with T&& ??
        Array2D& operator=(const Array2D& other) {}
        Array2D& operator=(Array2D&& other) {}


        void swap(Array2D &a, Array2D &b) {}
};

int main() {
    Array2D<int, 2, 2> arr = {1, 2, 3, 4};
    printf("arr : %d %d %d %d\n", arr[0][0], arr[0][1], arr[1][0], arr[1][1]);

    Array2D<int, 2, 2> arr2 = {{1, 2}, {3, 4}};
    printf("arr2 : %d %d %d %d\n", arr2[0][0], arr2[0][1], arr2[1][0], arr2[1][1]);
    arr2[0][0] = 5;
    printf("arr2 : %d %d %d %d\n", arr2[0][0], arr2[0][1], arr2[1][0], arr2[1][1]);
}