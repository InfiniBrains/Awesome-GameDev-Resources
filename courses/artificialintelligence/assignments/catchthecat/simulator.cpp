// DO NOT SUBMIT THIS FILE
// IMPROVE THIS SIMULATOR FOR YOUR OWN USE
// this code is not well tested, use as entry point for your own simulator
#include <iostream>
#include <vector>
#include "Cat.h"
#include "Catcher.h"

void print(const std::vector<bool>& state, int sideSize, std::pair<int,int> catPos, char turn) {
  std::cout << turn << " " << sideSize << " " << catPos.first << " " << catPos.second << std::endl;
  catPos.first += sideSize/2;
  catPos.second += sideSize/2;
  auto catPosIndex = catPos.second * sideSize + catPos.first;
  for(int y=0; y<sideSize; y++) {
    if (y % 2 == 1) std::cout << ' ';
    for (int x = 0; x < sideSize; x++) {
      if(y * sideSize + x == catPosIndex) {
        std::cout << 'C';
      } else
        std::cout << (state[y * sideSize + x] ? '#' : '.');
      if (x < sideSize - 1) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}

std::vector<bool> readBoard(int sideSize) {
  std::vector<bool> board;
  board.reserve(sideSize*sideSize);
  for(int i=0; i<sideSize*sideSize; i++) {
    char c;
    std::cin >> c;
    switch (c) {
      case '#':
        board.push_back(true);
        break;
      case '.':
      case 'C':
        board.push_back(false);
        break;
      default:
        i--;
        break;
    }
  }
  return board;
}

int main() {
  char turn;
  int sideSize;
  int catX, catY;
  std::vector<bool> blocked;
  std::cin >> turn >> sideSize >> catX >> catY;
  blocked = readBoard(sideSize);
  if(turn == 'C'){
    Cat cat;
    auto catMove = cat.move(blocked, {catX, catY}, sideSize);
    print(blocked, sideSize, {catMove.first, catMove.second}, 'T');
  } else {
    Catcher catcher;
    auto catcherMove = catcher.move(blocked, {catX, catY}, sideSize);
    blocked[(catcherMove.second + sideSize/2) * sideSize + catcherMove.first+sideSize/2] = true;
    print(blocked, sideSize, {catX, catY}, 'C');
  }
}