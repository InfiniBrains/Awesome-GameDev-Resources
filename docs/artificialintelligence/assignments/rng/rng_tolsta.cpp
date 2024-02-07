//#include <cstdint>
//#include <iostream>
//
//struct RNG {
//private:
//  uint32_t state;
//  void next(){
//    state ^= (state << 13);
//    state ^= (state >> 17);
//    state ^= (state << 5);
//  }
//public:
//  explicit RNG(uint32_t seed): state(seed) {}
//  int32_t range(int32_t min, int32_t max){
//    next();
//    if(max>min)
//      return min + (state % (max-min+1));
//    else
//      return max + (state % (min-max+1));
//  }
//};
//
//int main(){
//  uint32_t seed;
//  uint32_t N;
//  int32_t min, max;
//  std::cin >> seed >> N >> min >> max;
//  RNG rng(seed);
//  for(int i=0; i<N; i++)
//    std::cout << rng.range(min, max) << std::endl;
//}