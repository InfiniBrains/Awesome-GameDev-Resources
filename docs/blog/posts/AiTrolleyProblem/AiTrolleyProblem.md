---
date: 2023-07-28T18:42:39Z
categories:
  - ai
  - philosophy
authors:
  - tolstenko
---

# The problem with AI Trolley dilemma

[![What the self-driving car do?](what-should-the-self-driving-car-do.webp)](https://techcrunch.com/2016/10/04/did-you-save-the-cat-or-the-kid/)

The premise about the AI trolley dilemma is invalid. So the whole discussion about who should the car kill in a fatal situation. Let me explain why.

<!-- more -->

Yesterday I attended a conference about Ethics and AI, and the speaker mentioned the trolley dilemma. The question asked was "What should the self-driving car do?" and kind of forced us to take sides on the matter. 

- Kill the passengers; 
- Kill the pedestrians;

This is the same as the trolley problem but one difference. AI don't have morals, it will follow what is programmed without any hesitation. So the question is not what the AI should do, but what the programmer codes it to do.

Well, the whole premise on asking what should do "kill this, or that" is totally wrong. As a programmer myself, and knowing the limits of the system, I would never code a system to make such a decision. If the car is in a situation that it cannot break in time with the current limited vision, it should go slower. So no decision ever has to be made.

Let's do some math for you to see how this could be easily solved.

## The math

Let's use the standard formula for the distance needed to stop a car.

\[S = v*t + \frac{v^2}{2*u*g}\]

Where:

- \(S\) is the distance needed to stop;
- \(v\) is the speed of the car;
- \(t\) is the reaction time;
- \(v*t\) is the distance traveled during the reaction time;
- \(u\) is the tire friction factor;
- \(g\) is the gravity acceleration;
- \(\frac{v^2}{2*u*g}\) is the distance traveled during the breaking time;

If the car is going at \(100 km/h\) (\(27.7 m/s\), \(62.14 mi/h\)) and the reaction time of the AI is relatively fast, let's say \(0.2 s\), so the distance traveled to a complete sage stop would be:

\[S = 27.7 * 0.2 + \frac{27.7^2}{2*0.2*9.8} = 5.54 + 38.5 = 44.04 m\]

Which means that the car would need \(44.04 m\) to stop. So if the car cannot clearly see a distance greater than that, it should slow down. And this is the reason the self-driving AIs are said to be slow drivers.

