#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace mytestutil {

  std::string createRandomString(int cnum = 5, int seed = 0) {
    std::string rv;
    std::srand(static_cast<unsigned>(std::time(NULL)) + seed);
    int wd;
    for(int i = 0; i < cnum; i++){
      wd = std::rand() % 26 + 97;
      char wdbuf = static_cast<char>(wd);
      rv = rv + wdbuf;
    }
    return rv;
  }

  double createRandomDouble(int seed) {
    std::srand(static_cast<unsigned>(std::time(NULL)) + seed);
    double rv = static_cast<double>(std::rand() % 1000);
    rv /= 100;
    return rv;
  }

  int createRandomInt(int max, int seed) {
    std::srand(static_cast<unsigned>(std::time(NULL)) + seed);
    int rv = static_cast<double>(std::rand() % max);
    return rv;
  }
}

/* sample
int main(){
  for(int i = 0; i < 1000; i++){
    mytestutil::createRandomString(15, i);
  }
  return 0;
}
*/
