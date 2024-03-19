# Min-Max Algorithm

Commonly while you build a tree of options, (say path, decisions, states or anything else), you will have to make a decision at each node of the tree to deepen the search. The min-max algorithm is a nice and easy approach to solve this problem. It might be used in games, decision making, and other fields.

## Use cases

Min-Max algorithms shines in places where you will have to maximize the gain and minimize the loss.

## Algorithm

## Alpha beta prunning

### Alpha

- Alpha is the best value that the maximizer currently can guarantee at that level or above.
- It is the lower bound that a MAX node can be assigned.
- MAX node will only update the value of alpha if it finds a value greater than alpha.
- Starts at -∞.

### Beta

- Beta is the best value that the minimizer currently can guarantee at that level or above.
- It is the upper bound that a MIN node can be assigned.
- MIN node will only update the value of beta if it finds a value less than beta.
- Starts at +∞.