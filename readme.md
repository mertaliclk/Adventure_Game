# 🎲 Player Task Simulation Game

This C++ program simulates a turn-based task game where predefined players (Justin, Taylor, Katy) are assigned tasks and roll dice to determine their final scores. It features file input, data structures, string manipulation, randomization, and interactive menu functionality.

## 📁 Project Structure

```bash
.
├── main.cpp             # The main C++ file (your provided code)
├── randgen.h           # Random number generator header (required for RandGen class)
├── players.txt         # Input file for player names (one per line)
├── playerdata.txt      # Input file with player task counts and base scores
├── tasks.txt           # List of tasks that can be assigned to players

🧩 Features
Load player names from a file

Load each player's number of tasks and base score

Load a global list of task types

Assign tasks to specific players

Simulate dice rolls to generate scores

View player stats, task distribution, and high score

Interactive console-based menu

🚀 Getting Started
Prerequisites
Ensure you have a C++ compiler that supports C++11 or higher. You also need to implement or include a randgen.h header for random number generation.

Compilation

g++ -o game main.cpp


Run

./game

🧠 How It Works
The user is prompted to input three file names.

Players are loaded and initialized from players.txt.

Each player's number of tasks and base score is read from playerdata.txt.

Tasks are read from tasks.txt but task assignment is hardcoded for each player.

The game simulates a series of dice rolls per player, and tasks + rolls determine the final score.

A menu allows you to:

Show player statistics

Display the highest scorer

Display the number of each task assigned

Show how many times a 6 was rolled across all players