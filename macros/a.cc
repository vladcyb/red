#include <iostream>
#include <chrono>

#define TIME_TEST(func) \
            TimeTest(func, #func)
#define PRINT(x) cout << #x
#define print PRINT(

using namespace std;

void Foo1(){
    for(int i = 0; i < 100000; ++i){
        cout << i << ' ';
    }
    cout << endl;
}

void Foo2(){
    for(int i = 0; i < 1000000; ++i){
        cout << i << ' ';
    }
    cout << endl;
}

template <class T>
void TimeTest(T function, const string& func_name){
    auto startTime = chrono::steady_clock::now();
    function();
    auto stopTime = chrono::steady_clock::now();
    int ms = chrono::duration_cast<chrono::milliseconds>
        (stopTime - startTime).count();
    cout << func_name << " time: " << ms << " ms." << endl;
}

void PrintHello(){
    cout << "hello\n";
}

int main(){

    // TIME_TEST(Foo1);
    // TIME_TEST(Foo2);
    // TIME_TEST(PrintHello);
    // PRINT(hello world);
    cout << "This is a line number " << __LINE__ << " in file " << __FILE__ << endl;
    cout << "This is a line number " << __LINE__ << " in file " << __FILE__ << endl;
    print hello world);

    return 0;
}