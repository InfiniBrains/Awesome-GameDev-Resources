#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Cat : public IAgent {
  std::pair<int,int> move(const std::vector<bool>& world, std::pair<int,int> catPos, int sideSize ) override{
    return {0,0}; // todo: change this
  }
};
#endif