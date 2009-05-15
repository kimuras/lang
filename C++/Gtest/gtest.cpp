#include <iostream>
#include <string>
#include <gtest/gtest.h> 

const std::string SampleModStatus = "hoge";
const std::string DefaultModStatus = "def";
const int SampleModNumber = 100;
const int DefaultModNumber = 10;

class Mod {
  std::string modStatus;
  int modNumber;

public:
  Mod() : modStatus(DefaultModStatus), modNumber(DefaultModNumber) {}
  ~Mod(){}
  bool setModStatus(const std::string& statusBuf)
  {
    bool err = false;
    modStatus = statusBuf;
    return !err;
  }

  const std::string getModStatus()
  {
    return modStatus;
  }

  bool setModNumber(const int num)
  {
    bool err = false;
    modNumber = num;
    return !err;
  }

  const int getModNumber()
  {
    return modNumber;
  }
};

TEST(Mod, ModStatutsTest) {
  Mod md;
  std::cerr << "put:" << SampleModStatus << std::endl;
  ASSERT_TRUE(md.setModStatus(SampleModStatus));
  ASSERT_STREQ((md.getModStatus()).c_str(), SampleModStatus.c_str());
  ASSERT_STRNE((md.getModStatus()).c_str(), DefaultModStatus.c_str());
}

TEST(Mod, ModNumberTest) {
  Mod md;
  ASSERT_EQ(DefaultModNumber, md.getModNumber());
  ASSERT_TRUE(md.setModNumber(SampleModNumber));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
