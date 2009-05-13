#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <iterator>
#include "../../Util/mytestutils.hpp"

namespace utilitymemo {
  const int testNumber = 10;

  void vectorPairMemo(){
    std::vector<std::pair<int, std::string> > vec;
    std::vector<std::pair<int, std::string> >::iterator vecIter;
    for(int i = 0; i < testNumber; i++){
      vec.push_back(std::make_pair(mytestutil::createRandomInt(1000, i), mytestutil::createRandomString(10, i)));
    }

    vecIter = vec.begin();
    while(vecIter != vec.end()){
      std::pair<int, std::string> content = *vecIter;
      std::cout << content.first << ":" << content.second << std::endl;
      vecIter++;
    }
  }

}

int main(){
  utilitymemo::vectorPairMemo();

  return 0;
}


