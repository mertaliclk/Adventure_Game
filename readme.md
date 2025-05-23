# Player Task Simulation Game

![C++](https://img.shields.io/badge/C++-11%2B-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey)

A turn-based task simulation game implemented in C++ that demonstrates file I/O operations, data structures, and interactive menu-driven functionality.

## 📋 Overview

This project simulates a turn-based task game where predefined players are assigned tasks and roll dice to determine their final scores. The game features dynamic player loading, task assignment, and score calculation through dice rolls.

## 🎯 Project Goals

- Demonstrate C++ file I/O operations
- Implement data structure management
- Create an interactive menu system
- Simulate random number generation
- Process and display game statistics

## 📊 Key Features

### Game Mechanics
- Dynamic player loading from file
- Task assignment system
- Dice roll simulation
- Score calculation and tracking
- Highest scorer identification

### Data Management
- File-based player data loading
- Task list management
- Score tracking and statistics
- Dice roll history
- Task distribution analysis

### User Interface
- Interactive console menu
- Player statistics display
- Task distribution view
- Dice roll statistics
- Highest scorer display

## 🛠️ Technologies Used

- C++11 or higher
- Standard Template Library (STL)
- File I/O operations
- Random number generation
- String manipulation
- Data structures

## 📈 Project Structure

```
.
├── main.cpp              # Main C++ source file
├── randgen.h            # Header for RandGen random number generator
├── players.txt          # Player names input file
├── playerdata.txt       # Player task counts and base scores
└── tasks.txt            # List of tasks to assign
```

## 💻 Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/player-task-simulation.git
cd player-task-simulation
```

2. Compile the program:
```bash
g++ -o game main.cpp
```

3. Run the game:
```bash
./game
```

## 🎮 How to Play

1. Prepare input files:
   - `players.txt`: List of player names
   - `playerdata.txt`: Task counts and base scores
   - `tasks.txt`: Available tasks

2. Start the game and follow the menu options:
   - View player statistics
   - Check highest scorer
   - Display task assignments
   - View dice roll statistics

## 📊 Game Statistics

The game tracks various statistics including:
- Individual player scores
- Task distribution
- Dice roll results
- Number of sixes rolled
- Highest scoring player

## 🎲 Game Rules

1. Players are loaded from the input file
2. Each player is assigned tasks
3. Dice rolls determine score modifiers
4. Final scores are calculated based on:
   - Base scores
   - Task completion
   - Dice roll results

## 👤 Author

Mert Ali Celik

## 🙏 Acknowledgments

- C++ Standard Library
- Open-source community
- Contributors and testers
- Educational resources
