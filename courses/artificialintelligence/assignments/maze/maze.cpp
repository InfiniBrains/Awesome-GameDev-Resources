#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
  Node(int x, int y)
  {
    X = x;
    Y = y;

    Walls.first = true;
    Walls.second = true;
  }

  int X, Y;
  bool Visited = false;
  pair<bool, bool> Walls;
};

bool CheckForNeighbors(Node* CurrentNode, vector<Node*>& NeighborList, const vector<vector<Node*>>& NodeList, int Rows, int Columns);

int main()
{
  int Columns, Rows, Seed;
  const int RandomLength = 100;
  int Random[RandomLength] = {72, 99, 56, 34, 43, 62, 31, 4, 70, 22, 6, 65, 96, 71, 29, 9, 98, 41, 90, 7, 30, 3, 97, 49, 63, 88, 47, 82, 91, 54, 74, 2, 86, 14, 58, 35, 89, 11, 10, 60, 28, 21, 52, 50, 55, 69, 76, 94, 23, 66, 15, 57, 44, 18, 67, 5, 24, 33, 77, 53, 51, 59, 20, 42, 80, 61, 1, 0, 38, 64, 45, 92, 46, 79, 93, 95, 37, 40, 83, 13, 12, 78, 75, 73, 84, 81, 8, 32, 27, 19, 87, 85, 16, 25, 17, 68, 26, 39, 48, 36};

  //Fill Nodes
  cin >> Columns >> Rows >> Seed;
  vector<vector<Node*>> NodeList( Rows , vector<Node*> (Columns));
  for (int i = 0; i < Rows; ++i)
  {
    for (int j = 0; j < Columns; ++j)
    {
      Node* ToCreate = new Node(j , i);
      NodeList[i][j] = ToCreate;
    }
  }

  //Depth First Search
  stack<Node*> Stack;
  Stack.push(NodeList[0][0]);
  while(!Stack.empty())
  {
    Node* CurrentNode = Stack.top();
    CurrentNode->Visited = true;

    vector<Node*> NeighborList;
    if(CheckForNeighbors(CurrentNode, NeighborList, NodeList, Rows, Columns))
    {
      int NumOfNeighbors = int(NeighborList.size());
      Node* TargetNode = nullptr;
      if(NumOfNeighbors == 1)
      {
        TargetNode = NeighborList.front();
      }
      else
      {
        int TargetIndex = Random[Seed] % NumOfNeighbors;
        Seed++;
        if(Seed >= RandomLength)
          Seed = 0;

        TargetNode = NeighborList[TargetIndex];
      }

      if(TargetNode->Y < CurrentNode->Y) CurrentNode->Walls.second = false;
      else if(TargetNode->X > CurrentNode->X) TargetNode->Walls.first = false;
      else if(TargetNode->Y > CurrentNode->Y) TargetNode->Walls.second = false;
      else if(TargetNode->X < CurrentNode->X) CurrentNode->Walls.first = false;

      Stack.push(TargetNode);
    }
    else
    {
      Stack.pop();
    }
  }

  //Build The Maze Top
  for (int i = 0; i < Columns; ++i)
  {
    if(NodeList[0][i]->Walls.second)
      cout << " " << "_";
  }

  cout << "  " << "\n";

  //Build Maze Core
  for(int i = 0; i < Rows; ++i)
  {
    for(int j = 0; j < Columns; ++j)
    {
      if(NodeList[i][j]->Walls.first)
      {
        cout << "|";
      }
      else
      {
        cout << " ";
      }

      if(i+1 < Rows)
      {
        if(NodeList[i+1][j]->Walls.second)
        {
          cout << "_";
        }
        else
        {
          cout << " ";
        }
      }
      else
      {
        cout << "_";
      }
    }

    cout << "| " << endl;
  }

  //Clean Up
  for (int i = 0; i < Rows; ++i)
  {
    for (int j = 0; j < Columns; ++j)
    {
      delete NodeList[i][j];
    }
  }
}

//Check the adjacent neighbors
bool CheckForNeighbors(Node* CurrentNode, vector<Node*>& NeighborList, const vector<vector<Node*>>& NodeList, int MaxRows, int MaxColumns)
{
  int checks = 0;

  //Test Up
  if(CurrentNode->Y - 1 >= 0)
  {
    Node* TopNode = NodeList[CurrentNode->Y - 1][CurrentNode->X];
    if(!TopNode->Visited)
    {
      NeighborList.push_back(TopNode);
      checks++;
    }
  }

  //Test Right
  if(CurrentNode->X + 1 < MaxColumns)
  {
    Node* RightNode = NodeList[CurrentNode->Y][CurrentNode->X + 1];
    if(!RightNode->Visited)
    {
      NeighborList.push_back(RightNode);
      checks++;
    }
  }

  //Test Down
  if(CurrentNode->Y + 1 < MaxRows)
  {
    Node* BottomNode = NodeList[CurrentNode->Y + 1][CurrentNode->X];
    if(!BottomNode->Visited)
    {
      NeighborList.push_back(BottomNode);
      checks++;
    }
  }

  //Test Left
  if(CurrentNode->X - 1 >= 0)
  {
    Node* LeftNode = NodeList[CurrentNode->Y][CurrentNode->X - 1];
    if(!LeftNode->Visited)
    {
      NeighborList.push_back(LeftNode);
      checks++;
    }
  }

  if(checks == 0) return false;

  return true;
}


