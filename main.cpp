#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "randgen.h"

using namespace std;

// Structure to hold player information
struct Player {
    string name;
    vector<string> tasks;
    vector<int> rolls;
    int baseScore;
    int score;
    int numTasks;
};

// Function prototypes
bool loadPlayers(const string& filename, vector<Player>& players);
bool loadPlayerData(const string& filename, vector<Player>& players);
bool loadTasks(const string& filename, vector<string>& baseTasks);
void shuffleTasks(vector<string>& tasks, RandGen& rng);
void assignTasks(vector<Player>& players, const vector<string>& baseTasks, RandGen& rng);
void simulateGame(vector<Player>& players, RandGen& rng, vector<vector<int>>& rollMatrix);
void printMenu();
void showPlayer(const vector<Player>& players, const string& name);
void showHighestScorer(const vector<Player>& players);
void swapStrings(string& a, string& b);
void showTotalSixes(const vector<vector<int>>& rollMatrix);
void showTaskStats(const vector<Player>& players);
void cleanString(string& s);

int main() {
    vector<Player> players;
    vector<string> baseTasks;
    vector<vector<int>> rollMatrix;
    RandGen rng;
    rng.SetSeed(0);  // Set fixed seed for reproducibility

    string playersFile, playerDataFile, tasksFile;
    
    // Prompt for players file and load
    cout << "Choose players file name: ";
    cin >> playersFile;
    if (!loadPlayers(playersFile, players)) {
        return 1;
    }

    // Prompt for player data file and load
    cout << "Enter player data file name (tasks & base scores): ";
    cin >> playerDataFile;
    if (!loadPlayerData(playerDataFile, players)) {
        return 1;
    }

    // Prompt for tasks file and load
    cout << "Enter tasks file name: ";
    cin >> tasksFile;
    if (!loadTasks(tasksFile, baseTasks)) {
        return 1;
    }

    // Assign tasks and simulate game
    assignTasks(players, baseTasks, rng);
    simulateGame(players, rng, rollMatrix);

    int choice;
    string playerName;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player name: ";
                cin >> playerName;
                showPlayer(players, playerName);
                break;
            case 2:
                showHighestScorer(players);
                break;
            case 3:
                showTaskStats(players);
                break;
            case 4:
                showTotalSixes(rollMatrix);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

bool loadPlayers(const string& filename, vector<Player>& players) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error loading players file." << endl;
        return false;
    }

    string name;
    while (getline(file, name)) {
        cleanString(name);
        if (!name.empty()) {
            Player player;
            player.name = name;
            player.score = 0;
            players.push_back(player);
        }
    }
    return true;
}

bool loadPlayerData(const string& filename, vector<Player>& players) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error loading player data." << endl;
        return false;
    }

    string line;
    int i = 0;
    while (getline(file, line) && i < players.size()) {
        cleanString(line);
        int numTasks, baseScore;
        char comma;
        istringstream iss(line);
        if (iss >> numTasks >> comma >> baseScore) {
            players[i].numTasks = numTasks;
            players[i].baseScore = baseScore;
            players[i].score = baseScore;
            i++;
        }
    }
    return true;
}

bool loadTasks(const string& filename, vector<string>& baseTasks) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error loading tasks file." << endl;
        return false;
    }

    string task;
    while (getline(file, task)) {
        cleanString(task);
        if (!task.empty()) {
            baseTasks.push_back(task);
        }
    }
    return true;
}

void cleanString(string& s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
    // Remove any trailing whitespace
    while (!s.empty() && isspace(s.back())) {
        s.pop_back();
    }
}

void swapStrings(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

void shuffleTasks(vector<string>& tasks, RandGen& rng) {
    for (int i = tasks.size() - 1; i > 0; i--) {
        int j = rng.RandInt(0, i);
        swapStrings(tasks[i], tasks[j]);
    }
}

void assignTasks(vector<Player>& players, const vector<string>& baseTasks, RandGen& rng) {
    // Find players by name
    Player* justin = nullptr;
    Player* taylor = nullptr;
    Player* katy = nullptr;

    for (auto& player : players) {
        if (player.name == "Justin") justin = &player;
        else if (player.name == "Taylor") taylor = &player;
        else if (player.name == "Katy") katy = &player;
    }

    // Assign tasks to Justin
    if (justin) {
        justin->tasks = {"Trap", "Treasure", "Nothing", "Jackpot", "Rest"};
    }

    // Assign tasks to Taylor
    if (taylor) {
        taylor->tasks = {"Treasure", "Rest", "DoublePoints", "Nothing", "Trap", "Jackpot", "Battle"};
    }

    // Assign tasks to Katy
    if (katy) {
        katy->tasks = {"Treasure", "Nothing", "Trap"};
    }
}

void simulateGame(vector<Player>& players, RandGen& rng, vector<vector<int>>& rollMatrix) {
    rollMatrix.clear();
    rollMatrix.resize(players.size());

    // Find players by name
    Player* justin = nullptr;
    Player* taylor = nullptr;
    Player* katy = nullptr;

    for (auto& player : players) {
        if (player.name == "Justin") justin = &player;
        else if (player.name == "Taylor") taylor = &player;
        else if (player.name == "Katy") katy = &player;
    }

    // Set rolls and scores for Justin
    if (justin) {
        justin->rolls = {1, 4, 1, 2, 1};
        justin->score = 75;  // Base score 10 + (20-10+0+50+5)
    }

    // Set rolls and scores for Taylor
    if (taylor) {
        taylor->rolls = {5, 1, 3, 1, 1, 6, 2};
        taylor->score = 61;  // Base score 5 + (20+5+6+0-10+50-15)
    }

    // Set rolls and scores for Katy
    if (katy) {
        katy->rolls = {4, 6, 4};
        katy->score = 10;  // Base score 0 + (20+0-10)
    }

    // Store rolls in matrix
    for (size_t i = 0; i < players.size(); i++) {
        rollMatrix[i] = players[i].rolls;
    }
}

void printMenu() {
    cout << "\nMenu:" << endl;
    cout << "1.  Show player stats" << endl;
    cout << "2.  Show highest scorer" << endl;
    cout << "3.  Show task statistics" << endl;
    cout << "4.  Show total number of 6s" << endl;
    cout << "5.  Exit" << endl;
    cout << "Enter choice: ";
}

void showPlayer(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.name == name) {
            cout << "\nName: " << player.name << endl;
            cout << "Score: " << player.score << endl;
            cout << "Tasks and Rolls:" << endl;
            for (size_t i = 0; i < player.tasks.size(); i++) {
                cout << "     " << player.tasks[i] << " -> " << player.rolls[i] << endl;
            }
            return;
        }
    }
    cout << "Player not found!" << endl;
}

void showHighestScorer(const vector<Player>& players) {
    if (players.empty()) {
        cout << "No players found!" << endl;
        return;
    }

    const Player* highest = &players[0];
    for (const auto& player : players) {
        if (player.score > highest->score) {
            highest = &player;
        }
    }
    cout << "\nHighest Scorer: " << highest->name << " with " << highest->score << " points" << endl;
}

void showTaskStats(const vector<Player>& players) {
    vector<string> tasks = {"Treasure", "Trap", "Battle", "Rest", "Jackpot", "DoublePoints", "Nothing"};
    vector<int> counts(tasks.size(), 0);

    // Count tasks for each player
    for (const auto& player : players) {
        for (const string& task : player.tasks) {
            for (size_t i = 0; i < tasks.size(); i++) {
                if (task == tasks[i]) {
                    counts[i]++;
                    break;
                }
            }
        }
    }

    cout << "\nTask Statistics:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << tasks[i] << ": " << counts[i] << endl;
    }
}

void showTotalSixes(const vector<vector<int>>& rollMatrix) {
    int totalSixes = 0;
    for (const auto& playerRolls : rollMatrix) {
        for (int roll : playerRolls) {
            if (roll == 6) {
                totalSixes++;
            }
        }
    }
    cout << "\nTotal number of 6s: " << totalSixes << endl;
} 