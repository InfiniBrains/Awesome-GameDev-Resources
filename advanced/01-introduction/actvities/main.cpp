#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
using namespace std;

// create a function that allocates memory on the heap and returns a raw pointer to it
char* allocateMemoryAndClear(int numBytes, char value) {
  // implement this function
}

// create a function that deallocates memory on the heap
void deallocateMemory(char*& ptr) {
  // implement this function
}


// DO NOT CHANGE THE CODE BELOW THIS LINE
TEST_CASE("allocateMemory") {
  char* ptr = allocateMemoryAndClear(3, 'u');
  CHECK(ptr != nullptr);
  CHECK(ptr[0] == 'u');
  CHECK(ptr[1] == 'u');
  CHECK(ptr[2] == 'u');
  deallocateMemory(ptr);
  CHECK(ptr == nullptr);
}