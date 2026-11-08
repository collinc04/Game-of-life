# John Conway's game of life

Conway's game of life is a famous 0-player game. It is a demonstration of emergent complexity that operates on a few simple rules:

- The board is comprised of squares known as cells
- Each cell can be either dead or alive
- An alive cell dies if it has more than 3 neighbors or less than 2
- If a dead cell has 3 neighbors it comes back to life

This is a fun little micro-project I made while procrastinating something else, mainly just to learn more about the game of life and emergent behavior.

One of the things that makes this game so famous is that there cells can form structures known as cellular automata that can move accross the screen. I've left
some example patterns to try at the bottom of this README

# Compilation instructions

run this command from root:

>make build <br>

alternatively,

>cd src <br>
>g++ main.cpp game.cpp -o cgl -lSDL2 <br>

The game can be played by clicking on a square to change it from alive to dead or dead to alive while the game is paused.
You can pause and unpause with the spacebar

# Fun automata to try

Still lives:

```

████          
████

Block

  ████
██    ██
  ████

Beehive

```

Oscillators:

```

██████

Blinker

  ██
██    ██
██    ██
    ██

Toad


```

Spaceships:

```
    ██
██  ██
  ████

Glider

  ████
████████
████  ████
    ████

Light weight spaceship

```

My favorites:

```
    ████

  ████████

████████████

  ████████

    ████

Diamond

██████  ██████
██  ██  ██  ██
████      ████
      ██  
████      ████
██  ██  ██  ██
██████  ██████

Lotus
```