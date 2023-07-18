# Pseudo Random Number Generation

You are a game developer in charge to create a fast an reliable random number generator for a procedural content generation system. The requirements are:

- Do not rely on external libraries;
- Dont need to be cryptographically secure;
- Be blazing fast;
- Fully reproducible via automated tests if used the same seed;
- Use exactly 32 bits as seed;
- Be able to generate a number between a given range, both inclusive.

So you remembered a strange professor talking about the xorshift algorithm and decided it is good enough for your use case. and with some small research you found a the Marsaglia "Xorshift RNGs". You decided to implement it and test it.

## XorShift

The xorshift is a family of pseudo random number generators created by George Marsaglia. The xorshift is a very simple algorithm that is very fast and have a good statistical quality. It is a very good choice for games and simulations.

`xorshift` is the process of shifting a number and then `xor`'ing it to the original value to create a new value. 

```value = value xor (value shift by number)```

The shift operators can be to the left `<<` or to the right `>>`. When shifted to the left, it is the same thing as multiplying by 2 at the power of the number. When shifted to the right, it is the same thing as dividing.

The `xorshift` algorithm from Marsaglia is a combination of 3 `xorshifts`: 

1. `xorshift` the seed by `13` bits to the left;
2. `xorshift` the seed by `17` bits to the right;
3. `xorshift` the seed by `5` bits to the left;
4. the current state of the seed is your current random number from $0$ to $2^{32}-1$.

In order to clamp a random number the value between two numbers (max and min), you should follow this idea:

```value = min + (random % (max - min + 1))```

## Input

Receives the seed, the number of random numbers to be generated and the range of the numbers should be in. The range is inclusive. All numbers are unsigned 32 bits integer.

```
1 1 0 99
```

## Output

The list of numbers to be generated, one per line.

```
WiP
```
