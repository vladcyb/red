#include "test_runner.h"
#include <sstream>
#include <string>

using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }
  bool IsLogFileNecessary() const { return log_file; }
  bool IsLogLineNecessary() const { return log_line; }
  void Log(const string& message){
      os << message << endl;
  }

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) {                                     \
    string prefix = "";                                             \
    if(logger.IsLogFileNecessary()){                              \
        prefix = __FILE__;                                         \
        if(logger.IsLogLineNecessary()){                            \
            prefix += ":";                                           \
        }                                                             \
    }                                                               \
    if(logger.IsLogLineNecessary()){                    \
        if(prefix.empty()){                                     \
            prefix += "Line ";                                  \
        }                                                   \
        prefix += to_string(__LINE__);                                 \
    }                                                           \
    if (!prefix.empty()){                                       \
        prefix += " ";                                                \
    }                                                                      \
    logger.Log(prefix + message);               \
}

void TestLog() {
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}