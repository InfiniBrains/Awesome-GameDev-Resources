# Flocking agents behavior assignment

You are in charge to implement some functions to make some AI agents flock together in a game.

## What is flocking?

Flocking is a behavior that is observed in birds, fish and other animals that move in groups. It is a very simple behavior that can be implemented with a few lines of code. The idea is that each agent will try to move towards the center of mass of the group (cohesion), and will try to align its velocity with the average velocity of the group (AKA alignment). In addition, each agent will try to avoid collisions with other agents (AKA avoidance).

In order to calculate the new position of the agent, we have to use some phisics formulas such as:

- $ \overrightarrow{F} = K_c*\hat{F_c} + K_s*\hat{F_s} + K_a*\hat{F_a} $
- $ \overrightarrow{V_{new}} = \overrightarrow{V_{cur}}+\frac{\overrightarrow{F}}{m} \cdot \Delta t $
- $ P_{new} = P_{cur}+\overrightarrow{V_{cur}} \cdot \Delta t + \frac{\overrightarrow{F}}{m} \cdot \frac{\Delta t^2}{2} $

!!! note "Notation"

    - $\overrightarrow{F}$ means a vector $F$ that has components. In a 2 dimensional vector it will hold $F_x$ and $F_y$. For example, if $F_x = 1$ and $F_y = 1$, then $\overrightarrow{F} = (1,1)$
    - $\overrightarrow{P_1P_2}$ means the vector that goes from $P_1$ to $P_2$. It is the same as $P_2-P_1$
    - The modulus notation means the length (magnitude) of the vector. $|\overrightarrow{F}| = \sqrt{F_x^2+F_y^2}$ For example, if $\overrightarrow{F} = (1,1)$, then $|\overrightarrow{F}| = \sqrt{2}$
    - The hat ^ notation means the unitary vector of the vector. $\hat{F} = \frac{\overrightarrow{F}}{|\overrightarrow{F}|}$ For example, if $\overrightarrow{F} = (1,1)$, then $\hat{F} = (\frac{1}{\sqrt{2}},\frac{1}{\sqrt{2}})$
    - The hat notation over 2 points means the unit vector that goes from the first point to the second point. $\widehat{P_1P_2} = \frac{\overrightarrow{P_1P_2}}{|\overrightarrow{P_1P_2}|}$ For example, if $P_1 = (0,0)$ and $P_2 = (1,1)$, then $\widehat{P_1P_2} = (\frac{1}{\sqrt{2}},\frac{1}{\sqrt{2}})$

Where:

- $\overrightarrow{F}$ is the force applied to the agent; 
- $\overrightarrow{V}$ is the velocity of the agent;
- $P$ is the position of the agent; 
- $m$ is the mass of the agent;
- $\Delta t$ is the time frame (1/FPS); 
- $cur$ is the current value of the variable; 
- $new$ is the new value of the variable to be used in the next frame.

!!! note

    For simplicity, we are going to assume that the mass of all agents is 1, and the time frame is 0.017s.

It is your job to implement those 3 behaviors following the ruleset below:

### Cohesion

Apply a force towards the center of mass of the group.

1. The neighbors of an agent are all the other agents that are within a certain radius of the agent;
2. Compute the location of the center of mass of the group ($P_{CM}$);
3. Compute the force that will move the agent towards the center of mass($F_{cohesion}$);
4. The farther the agent is from the center of mass, the force increases linearly up to the limit of the cohesion radius $r_c$.

$$ 
P_{CM} = \frac{\sum_{i=0}^{n-1} P_i}{n}
$$

$$
F_c = \begin{cases}
    \frac{ \overrightarrow{P_{a}P_{CM}} }{r_c} & \text{if } |\overrightarrow{P_{a}P_{CM}}| \leq r_c \\
    0 & \text{if } |\overrightarrow{P_{a}P_{CM}}| > r_c
\end{cases}
$$

### Separation

It will move the agent away from other agents when they get too close.

1. The neighbors of an agent are all the other agents that are within the separation radius of the agent;
2. If the distance to a neighbor is less than the separation radius, then the agent will move away from it inversely proportionally to the distance between them.
3. Accumulate the forces that will move the agent away from each neighbor ($F_{separation}$);
4. Clamp the force to a maximum value of $F_{Smax}$.

$$
F_s = \sum_{i=0}^{n-1} \begin{cases}
      0 & \text{if } |\overrightarrow{AN_i}| = 0 \\
      \widehat{AN_i} / |\overrightarrow{AN_i}| & \text{if } 0 < |\overrightarrow{AN_i}| \leq r_s \\
    0 & \text{if } |\overrightarrow{AN_i}| > r_s
\end{cases}
$$

The force will go near infinite when the distance between the agent and the neighbor is 0. To avoid this, after accumulating all the influences from every neighbor, the force will be clamped to a maximum value of $F_{Smax}$.

### Alignment

It is the force that will align the velocity of the agent with the average velocity of the group.

1. The neighbors of an agent are all the agents that are within the alignment radius of the agent, including itself;
2. Compute the average velocity of the group ($V_{avg}$);
3. Compute the force that will move the agent towards the average velocity ($F_{alignment}$);

$$
V_{avg} = \frac{\sum_{i=0}^{n-1} V_i}{n}
$$

## Input

The input consists in a list of parameters followed by a list of agents. The parameters are:

- $r_c$ - Cohesion radius
- $r_s$ - Separation radius
- $F_{Smax}$ - Maximum separation force
- $r_a$ - Alignment radius
- $K_c$ - Cohesion constant
- $K_s$ - Separation constant
- $K_a$ - Alignment constant
- $N$ - Number of agents

Every agent is represented by 4 values in the same line, separated by a space:

- $x$ - X coordinate
- $y$ - Y coordinate
- $vx$ - X velocity
- $vy$ - Y velocity

After reading the agents data, the program should read the time frame ($\Delta t$), simulate the agents and then output the new position of the agents in the same sequence and format it was read. The program should keep reading the time frame and simulating the agents until the end of the input.

## Output

## Test cases