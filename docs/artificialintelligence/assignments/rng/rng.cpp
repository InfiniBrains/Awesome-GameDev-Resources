// add your imports here
#include <fstream>
#include <iostream>
#include <istream>
const std::string TEST_FOLDER = "\\tests\\";
unsigned int xorShift(unsigned int seed, int r1, int r2);
int main(){
  // code here
  unsigned int seed, N, min, max;
  std::cin >> seed >> N >> min >> max;
  unsigned int i;
  for(i = N; i >= 1; i--)
  {
    //Run xor shift
    seed = xorShift(seed, min, max);
  }
}
//The purpose of this function is to take the number and xor shift it to output a pseudo-random number
    unsigned int xorShift(unsigned int seed, int r1, int r2)
{
  seed = seed xor (seed << 13);
  seed = seed xor (seed >> 17);
  seed = seed xor (seed << 5);
  int value = r1 + (seed % (r2 - r1 + 1)); //clamps the value to between r1 and r2
          //output the new values
          std::cout << value << std::endl;
  return seed;
}
