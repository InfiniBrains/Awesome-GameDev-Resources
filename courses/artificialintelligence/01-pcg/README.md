# Procedural Content Generation

One of the more emergent fields in AI for games is Procedural Content Generation - PCG. It is a technique to algorithmically generate game content and assets, such as levels, textures, sound, enemies, quests, and more. The goal of PCG is to create unique and varied content without the need for manual labor. This can save time and money during development, and also allow for a more dynamic and replayable experience for the player. There are many different algorithms and techniques used in PCG, such as random generation, evolutionary algorithms, and rule-based systems.

Level generation. Instead of manually designing each level, a PCG algorithm can be used to generate a new level every time the player starts a new game or enters a new area. This allows for a large number of unique levels without the need for a designer to create each one individually.

Enemies and NPCs. Instead of manually designing each character, a PCG algorithm can be used to randomly generate the appearance, abilities, and behavior of enemies. This can create a more diverse and unpredictable gameplay experience for the player.

PCG can also be used in other areas of game development such as textures, terrain, narrative, quests, and sound effects. With PCG, the possibilities are endless.

It's important to note that PCG is not a replacement for human creativity, but rather a tool that can help create new and unique content. It is often used in conjunction with manual design and artistic direction.

## Procedural Scenario Generation
Procedural scenario generation is a specific application of procedural content generation that is used to create unique and varied scenarios or missions in a game. These scenarios can include objectives, enemies, and environmental elements such as terrain and buildings.

One popular technique is rule-based systems, where a set of predefined rules are used to generate new scenarios. For example, a rule could be that the player must navigate through a forest to reach a specific location, and another rule could be that the player must defeat a certain number of enemies along the way. These rules can be combined in different ways to create a wide variety of scenarios.

Another technique used in procedural scenario generation is the use of random generation. In this approach, elements of the scenario such as objectives, enemies, and terrain are randomly generated. This can create a large number of unique scenarios, but the quality of the scenarios may be more inconsistent.

Procedural scenario generation can be used in various types of games, including first-person shooters, open-world games, and strategy games. It allows for a more dynamic and replayable experience for the player, as well as saving development time and costs.

## Procedural Terrain Generation

Procedural terrain generation is a technique used in game development to algorithmically generate realistic and diverse terrain. This can include features such as mountains, valleys, rivers, and forests. The goal of procedural terrain generation is to create unique and varied terrain without the need for manual labor.

One common technique used in procedural terrain generation is fractal noise, which uses mathematical algorithms to generate random patterns that resemble natural terrain. These patterns can be combined and layered to create more complex terrain features. Another technique used in procedural terrain generation is erosion simulation, which simulates the effects of erosion and weathering on the terrain to create more realistic landscapes.

### Procedural Terrain Generation

## Random Number Generation

## Noise Generation

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