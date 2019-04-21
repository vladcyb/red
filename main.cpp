#include <string>
#include <vector>
using namespace std;

#define GET_UNIQUE_VAR(lineno) var ## lineno
#define UNIQ_ID2(lineno) GET_UNIQUE_VAR(lineno)
#define UNIQ_ID UNIQ_ID2(__LINE__)

int main() {
    int UNIQ_ID = 0;
    string UNIQ_ID = "hello";
    vector<string> UNIQ_ID = {"hello", "world"};
    vector<int> UNIQ_ID = {1, 2, 3, 4};

    return 0;
}