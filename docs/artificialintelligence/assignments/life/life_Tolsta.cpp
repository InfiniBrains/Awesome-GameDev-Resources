#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> board;

struct Point2D {
  Point2D(int x, int y): x(x), y(y) {}
  int x;
  int y;
  void print(){
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

vector<vector<bool>> generateBoard(Point2D limits) {
  vector<vector<bool>> board;
  for(int lin=0; lin<limits.y; lin++){
    vector<bool> line;
    line.reserve(limits.x);
    for(int col=0; col<limits.x; col++)
      line.push_back(false);
    board.push_back(line);
  }
  return board;
}

void readBoardFromConsole(Point2D limits){
  for(int lin=0; lin<limits.y; lin++) {
    string line;
    cin >> line;
    for(int col=0; col<limits.x; col++)
      board[lin][col] = (line[col] == '#');
  }
}

void printBoard(Point2D limits){
  for(int lin=0; lin<limits.y; lin++) {
    for(int col=0; col<limits.x; col++)
      board[lin][col] ? cout << '#' : cout << '.';
    cout << endl;
  }
}

Point2D getNorth(Point2D point, Point2D limits){
  point.y--;
  if(point.y < 0)
    point.y = limits.y-1;
  return point;
}

Point2D getSouth(Point2D point, Point2D limits){
  point.y++;
  point.y %= limits.y;
  return point;
}

Point2D getEast(Point2D point, Point2D limits){
  point.x++;
  point.x %= limits.x;
  return point;
}

Point2D getWest(Point2D point, Point2D limits){
  point.x--;
  if(point.x < 0)
    point.x = limits.x-1;
  return point;
}

int countNeighbors(Point2D p, Point2D limits){
  int count = 0;

  auto north = getNorth(p, limits);
  auto south = getSouth(p, limits);
  auto east = getEast(p, limits);
  auto west = getWest(p, limits);
  auto northEast = getEast(north, limits);
  auto northWest = getWest(north, limits);
  auto southEast = getEast(south, limits);
  auto southWest = getWest(south, limits);

  if(board[north.y][north.x])
    count++;
  if(board[south.y][south.x])
    count++;
  if(board[east.y][east.x])
    count++;
  if(board[west.y][west.x])
    count++;
  if(board[northEast.y][northEast.x])
    count++;
  if(board[northWest.y][northWest.x])
    count++;
  if(board[southEast.y][southEast.x])
    count++;
  if(board[southWest.y][southWest.x])
    count++;

  return count;
}

void step(Point2D limits) {
  auto newBoard = board;

  for(int l=0;l<limits.y;l++){
    for(int c=0; c<limits.x; c++) {
      auto neighbors = countNeighbors({c, l}, limits);
      auto isAlive = board[l][c];
      if(isAlive && (neighbors == 2 || neighbors == 3))
        newBoard[l][c] = true;
      else if(!isAlive && neighbors == 3)
        newBoard[l][c] = true;
      else
        newBoard[l][c] = false;
    }
  }
  board = newBoard;
}

void simulate(Point2D limits, int steps) {
  for(int i=0; i<steps; i++)
    step(limits);
}

int main(){
  int columns, lines, steps;

  // read the input
  cin >> columns >> lines >> steps;

  // clear the board
  board = generateBoard({columns, lines});

  // read the board
  readBoardFromConsole({columns, lines});

  // simulate
  simulate({columns, lines}, steps);

  // print the board
  printBoard({columns, lines});

  return 0;
};