# 🎲 Player Task Simulation Game

Welcome to the **Player Task Simulation Game**, a C++ program that simulates a turn-based task game where predefined players (Justin, Taylor, Katy) are assigned tasks and roll dice to determine their final scores. This project demonstrates file input/output, data structures, string manipulation, randomization, and interactive menu-driven functionality.

---

## 📁 Project Structure

.
├── main.cpp # Main C++ source file
├── randgen.h # Header for RandGen random number generator
├── players.txt # Player names input file (one name per line)
├── playerdata.txt # Player task counts and base scores input file
├── tasks.txt # List of tasks to assign to players


---

## 🧩 Features

- Load player names dynamically from a file  
- Load each player's task count and base score  
- Load a global list of task types  
- Assign tasks to players (currently hardcoded)  
- Simulate dice rolls to generate scores  
- Display player statistics and task distributions  
- Identify and display the highest scorer  
- Show the count of dice rolls resulting in a six  
- Interactive, console-based menu system  

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or higher  
- The `randgen.h` header file (for the RandGen class used for random number generation)  

### Compilation
g++ -o game main.cpp
### Run the game
./game




## 🧠 How It Works
The program prompts the user to input the names of three files:

players.txt for player names

playerdata.txt for task counts and base scores

tasks.txt for the list of tasks

Players are loaded and initialized from players.txt.

Each player's task count and base score are read from playerdata.txt.

Tasks are read from tasks.txt (task assignment is hardcoded).

The game simulates dice rolls for each player, combining task assignment and roll results to compute final scores.

An interactive menu allows the user to:

View player statistics

See the highest scorer

Display task assignment counts

Check how many times the number six was rolled across all players

Feel free to fork, star, and contribute to this project!
Happy gaming! 🎮
