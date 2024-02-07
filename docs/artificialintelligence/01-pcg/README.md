# Procedural Content Generation

PCG is a technique to algorithmically generate game content and assets, such as levels, textures, sound, enemies, quests, and more. The goal of PCG is to create unique and varied content without the need for manual labor. This can save time and money during development, and also allow for a more dynamic and replayable experience for the player. There are many different algorithms and techniques used in PCG, such as random generation, evolutionary algorithms, and rule-based systems.

PCG can also be used in other areas of game development such as textures, terrain, narrative, quests, and sound effects. With PCG, the possibilities are endless. It's important to note that PCG is not a replacement for human creativity, but rather a tool that can help create new and unique content. It is often used in conjunction with manual design and artistic direction.

## Procedural Scenario Generation

Procedural scenario generation is a specific application of procedural content generation that is used to create unique and varied scenarios or missions in a game. These scenarios can include objectives, enemies, and environmental elements such as terrain and buildings.

Two common techniques are rule and noise based algorithms, and you can combine both. But first let's cover Pseudo Random Number Generation.

## Random Number Generation

There are a plethora of algorithms to generate random numbers. The expected interface for a random number function is to just call it, (i.e. `random()`) and receive, ideally, a high quality and non-deterministic random number. 

In the best scenario, some systems possess a random device (i.e. an antenna capturing electrical noise from the environment), and the random function will be a system call to it. Natural noise are stateless and subject only to the environmental influence that are (arguably) impossible to tamper. It is an awesome source of noise, but the problem is that device call is slow and not portable. So we need to use pseudo random number generators.

### Pseudo Random Number Generation

In this field, the main challenge is to create a function capable to generate a sequence of numbers that are statistically random or, at least, can pass some tests of randomness at some degree of quality. The function must be fast, portable and deterministic, so it can be reproduced in different machines and platforms The function must be able to generate the same sequence of numbers given the same seed.

A common PRNG is XORShift. It is fast, portable and deterministic, but do not deliver a high quality of randomness. It is a good choice for games, but not for cryptography.

```cpp
uint32_t xorshift32()
{
    // seed and state 'x' must be non-zero
    // you should implement the state initialization differently
    static uint32_t x = 123456789;
    // XOR the state with itself shifted by 13, 17 and 5.
    // you can use other shifts, but these are the most common
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
```

As you might notice, the function is not stateless, so you have to initialize the state with a seed. It uses the previous state to generate the next one. A common practice is to use the system time as seed, or a random device call, but you can use any number you want. The seed is the only way to reproduce the sequence of numbers.

Another one is the Mersenne Twister. It is a high quality PRNG, but it is a bit slower.


## Noise Generation

### Noise based Procedural Terrain Generation

## Wave function collapse

# Homework

You can either use your favorite game engine or use [this repository](https://github.com/InfiniBrains/mobagen/tree/master/examples/scenario) as an entry point.
1. Use a noise function to generate a heightmap. Optional: Use octaves and fractals to make it feels nicer;
2. Implement islands [reference](https://www.redblobgames.com/maps/terrain-from-noise/#islands) or any other meaningful way to make hydraulically erosion apparent;
3. Implement Hydraulic Erosion to make the scenario feels more realistic. See the section 'HYDRAULIC EROSION' from book AI for Games Third ed. IanMillington;
4. Render the heightmap with biomes colors to make more understandable(ocean, sand, forest, mountains, snow...). Optionally use gradient / ramp functions instead of conditionals.

# References
Procedural content generation is a broad topic, and we need to narrow down some applications and algorithms to cover. I carefully covered Maze generation and Scenario Generation here https://github.com/InfiniBrains/mobagen and I invite you to check the examples named `maze` and `scenario`. Besides that, Amit Patel have a really nice website focused in many game algorithms, check it out and support his work https://www.redblobgames.com/

Please refer to the book below. We are going to follow the contents mostly from it.

<a href="https://www.amazon.com/AI-Games-Third-Ian-Millington/dp/0367670569?hvadid=509062326676&hvpos=&hvnetw=g&hvrand=14550697854366430846&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003006&hvtargid=pla-946782971463&psc=1&linkCode=li2&tag=tolstenko-20&linkId=e9ea9d7c2c4131719ef523890cd3d5db&language=en_US&ref_=as_li_ss_il" target="_blank"><img border="0" src="//ws-na.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=0367670569&Format=_SL160_&ID=AsinImage&MarketPlace=US&ServiceVersion=20070822&WS=1&tag=tolstenko-20&language=en_US" ></a><img src="https://ir-na.amazon-adsystem.com/e/ir?t=tolstenko-20&language=en_US&l=li2&o=1&a=0367670569" width="1" height="1" border="0" alt="" style="border:none !important; margin:0px !important;" />
Book: https://amzn.to/3kvtNDS