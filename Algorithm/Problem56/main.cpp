#include <gsl/gsl>
#include <vector>

// Select algorithm

// Book Example
struct book
{
   int         id;
   std::string title;
   std::string author;
};

template <typename T, typename F>
class BookIter {
    private:
    T&& cont;
    F&& func;

    template <typename IterT>
    struct Iterator {
        IterT iter;
        F& func;

        Iterator(IterT&& iter, F& func) : 
            iter(std::forward<IterT>(iter)), func(func) 
        {
            // Do Nothing
        }

        Iterator& operator++() {
            ++iter;
            return *this;
        }

        auto operator*() {
            return func(*iter);
        }

        bool operator!=(Iterator const& other) {
            return iter != other.iter;
        }
    };

    using value_type = T;
    using reference = T&;
    using const_reference = T const&;
    using iterator = Iterator<typename std::decay_t<T>::iterator>;
    using const_iterator = Iterator<typename std::decay_t<T>::const_iterator>;

    public:
    BookIter(T&& cont, F&& func):
    :cont(cont), func(func) 
    { }

    iterator begin() {
        return iterator(range.begin(), func);
    }

    const_iterator begin() const {
        return const_iterator(range.cbegin(), func);
    }

    iterator end() {
        return iterator(range.end(), func);   
    }

    const_iterator end() const {
        return const_iterator(range.cend(), func);
    }
}

std::vector<book> books{
   {101, "The C++ Programming Language", "Bjarne Stroustrup"},
   {203, "Effective Modern C++", "Scott Meyers"},
   {404, "The Modern C++ Programming Cookbook", "Marius Bancila"}
};

template <typename T, typename F>
auto select(T&& cont, F&& func) {

    return BookIter<T, F>(std::forward<T>(cont), std::forward<F>(func));
}

auto titles = select(books, [](book const & b) {return b.title;});

int main(int argc, char* argv[])
{
    for (auto const& title : titles)
       std::cout << title << '\n';
    return 0;
}
