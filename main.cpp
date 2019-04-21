#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define AS_KV(x) #x << " = " << x

template<class T>
class Vec{
public:
    Vec(){}
    Vec(const vector<T>& v){
        assign(v);
    }
    T const& At(size_t i) const {
        return v_.at(i);
    }
    T Back() const {
        return v_.back();
    }
    void assign(const vector<T>& v){
        v_ = v;
    }
    size_t Size() const {
        return v_.size();
    }
    bool Empty() const {
        return v_.empty();
    }
private:
    vector<T> v_;
};

template<class T>
ostream& operator<<(ostream& stream, const Vec<T>& v){
    stream << "{";
    for(size_t i = 0; i + 1 < v.Size(); ++i){
        stream << v.At(i) << ", ";
    }
    if (!v.Empty()){
        stream << v.Back();
    }
    stream << "}";
    return stream;
}

int main() {
    Vec<int> v1({1, 2, 3, 4, 5});
    Vec<string> v2({
        "first",
        "second",
        "third"
    });
    cout << v1 << endl;
    cout << v2 << endl;

    return 0;
}