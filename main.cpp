#include <iostream>
#include <vector>

using namespace std;

template<class Iterator>
struct IteratorRange{
private:
    Iterator first, last;
public:
    IteratorRange(Iterator f, Iterator l)
    : first(f)
    , last(l) {
    }
    Iterator begin(){
        return first;
    }
    Iterator end(){
        return last;
    }
};

template<class T>
IteratorRange<class vector<T>::iterator> Head(
    vector<T>& v, size_t top
){
    return {
        v.begin(), next(v.begin(), min(top, v.size()))
    };
}

template<class Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end){
    return IteratorRange<Iterator>{begin, end};
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6};

    IteratorRange second_half(
        begin(v) + v.size() / 2, end(v)
    );

    for(int x : second_half){
        cout << x << ' ';
    }

    return 0;
}