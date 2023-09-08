# Catch the Cat

You are in charge of creating 2 agents that will be playing the game of [Catch the Cat](https://llerrah.com/cattrap.htm).

## Game rules

The game is played on a NxN board where N is an odd number that follows the sequence of `1+4*x` with `x` starnig from `1`: `5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, ...`. The game starts with a cat in the center of the board, and it starts with some random blocks placed randomly.

The game is played in turns, where each player can move the cat or a catcher. 

### Board

The board position follows `{x, y}` notation.

The center of the board is `{0,0}` and the board is a square with `N` cells on each side.

The board is a pointy top hexagon with the first line aligned to the left:

```
 /  \ /  \ /  \ 
|-1-1| 0-1| 1-1|
 \  / \  / \  / \
  |-1 0| 0 0| 1 0|
 /  \ /  \ /  \ /
|-1 1| 0 1| 1 1|
 \  / \  / \  /
```

### Moves

The Cat moves in any of the 6 immediate neighbors, but it cannot move to a blocked cell.

The Catcher moves by blocking a cell. A cell can be blocked only once each turn.

### Win condition

1. If the cat is surrounded by blocked cells in all 6 directions, it cannot move and the catcher wins.
2. If the cat reaches a border cell, it wins.
3. If the cat makes invalid moves, it loses. Invalid moves are:

    - Move to a blocked cell;
    - Move to a cell that is not a neighbor;
    - Stay in the same cell;

4. The catcher makes invalid moves, it loses. Invalid moves are:

    - Block an already blocked cell;
    - Block a cell outside the board;
    - Block a cell where the cat is;

## Suggested coding interface

The move function should return a `std::pair<int, int>` with the `{x, y}` position. And receives as parameter `const std::vector<bool>&` as the blocked cells, where `true` means blocked and `false` means free, and `const std::pair<int, int>&` as the current position of the cat.

Suggested interface of an agent:

```cpp
class Agent {
public:
    Agent() = default;
    virtual ~Agent() = default;

    virtual pair<int, int> move(const vector<bool>& blocked, const pair<int, int>& cat) = 0;
};
```

## Competition

All students enrolled in the competition will submit both agents. The agents will play against each other and the winner will be the one that wins the most games. In case of a tie, the winner will be the one that wins the fastest game.