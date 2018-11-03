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
        
        Array2D(const Array2D &other) : Array2D() {
            for (size_t i = 0; i < ROW * COL; i++)
                storage[i] = other.storage[i];
        }

        Array2D(Array2D &&other) : Array2D() {
            storage = std::move(other.storage);
            array = std::move(other.array);
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
        Array2D& operator=(const Array2D& other) {
            for (size_t i = 0; i < ROW * COL; i++)
                storage[i] = other.storage[i];
            return *this;
        }
        // move assign
        Array2D& operator=(Array2D&& other) {
            storage = std::move(other.storage);
            array = std::move(other.array);
            return *this;
        }

        // friend???
        friend void swap(Array2D &a, Array2D &b) {
            Array2D tmp = std::move(a);
            a = std::move(b);
            b = std::move(tmp);
        }

        void print() {
            for (uint32_t i = 0; i < ROW; i++) {
                for (uint32_t j = 0; j< COL; j++) 
                    printf("%d ", array[i][j]);
            }
            printf("\n");
        }
};

int main() {

    Array2D<int, 2, 2> arr = {1, 2, 3, 4};
    printf("arr : %d %d %d %d\n", arr[0][0], arr[0][1], arr[1][0], arr[1][1]);

    Array2D<int, 2, 2> arr2 = {{1, 2}, {3, 4}};
    printf("arr2 : "); arr2.print();
    arr2[0][0] = 5;
    printf("arr2 : "); arr2.print();

    printf("Assign arr2 to arr\n");
    arr = arr2;
    printf("arr : "); arr.print();

    Array2D<int, 2, 2> arr3 = {9,8,7,6};
    printf("Swap arr3 and arr\n");
    swap(arr, arr3);
    printf("arr : "); arr.print();
    printf("arr3 : "); arr3.print();
}