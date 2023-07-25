# Zea's Tic Tac Toe

![Screenshot of Zea's Tic Tac Toe](https://github.com/zea17/dragon-bank/assets/93328643/7eced1bd-a69d-44c9-949b-e38f072a713e)

A C++ Tic Tac Toe Game for the Terminal that has:

- 🎎 Two player game play that you can play with your friend

- 🤖 AI with an easy and medium level you may win, and a hard level you'll never ever win.

- 🏝️ Saves your game with each play so that you can close the app in the middle of the game and come back to it whenever you want to!

- 💥 Play the biggest Tic Tac Toe of your life, not just a 3x3 game, but go bigger! play a 7x7, or even a 17x17 if you want to!

## Really Hard AI

If you play the game on the Hard level, the AI will throw a lots of hard plays at you. It defends really well, and plans for win in ways you cannot think of. Playing with strategies like Forking, Center Attack, Corner Protection, and, Futuristic Win Chance Computation. You'll never defeat it!


## How to run?

### On Desktop

You need to have GCC or LLVM+Clang (macOS) on your system + installation of BASH. Then you should clone this repo and build it with:

```bash
# Cloning the repo
% git clone https://github.com/zea17/TicTacToe.git xo
% cd xo

# Building the
% bash build.sh

# Installing the app and giving it permission to run:
% mv ./bin/ttt /usr/local/bin/ttt
% chmod u+x /usr/local/bin/ttt
```


### On [iSH App](https://ish.app)

Building on iSH is exactly like the desktop, however you must have
the GCC, Git and Bash installed. You can install them by running:

```bash
# Install GCC + Git + BASH
% apk add build-base
% apk add git
% apk add bash
```

<br>

Copyright &copy; 2023-present by Zea. All Rights Reserved.