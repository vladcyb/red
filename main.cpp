#include <iostream>
#include <vector>

using namespace std;

template<class Iterator>
struct IteratorRange{
    Iterator first, last;

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

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    for(int& x : Head(v, 3)){
        ++x;
    }
    for(int x : v){
        cout << x << ' ';
    }
    return 0;
}