#include <iostream>
#include <array>
#include <algorithm> // for std::all_of
#include <random> // for random number generation (modern way)

// TIC TAC TOE GAME
using namespace std;

// Use a type alias for readability
using Board = std::array<char, 9>;

void drawBoard(const Board& spaces) {
    cout << "\nGame Board:\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << spaces[i] << " | " << spaces[i + 1] << " | " << spaces[i + 2] << "\n";
        if (i < 6) cout << "---|---|---\n";
    }
    cout << endl;
}

void playerMove(Board& spaces, char player) {
    int number;
    while(true) {
        cout << "Enter a number (1-9) to place your " << player << ": ";
        if(cin >> number && number >= 1 && number <= 9 && spaces.at(number - 1) == ' ') {
            spaces[number - 1] = player; // Place the player's mark on the board
            break;
        } else {
            cout << "Invalid move. Please try again." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Discard invalid input
        }
    }
}

void computerMove(Board& spaces, char computer) {
    int number;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);

    while(true) {
        number = dis(gen); // Generate a random number between 0 and 8
        if(spaces[number] == ' ') { // Check if the space is empty
            spaces[number] = computer; // Place the computer's mark on the board
            break;
        }
    }
}

bool checkWinner(const Board& spaces, char player, char computer) {
    int winningCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6} // Diagonals
    };

    for(int i = 0; i < 8; i++) {
        if(spaces[winningCombos[i][0]] != ' ' &&
           spaces[winningCombos[i][0]] == spaces[winningCombos[i][1]] &&
           spaces[winningCombos[i][1]] == spaces[winningCombos[i][2]]) {
            if(spaces[winningCombos[i][0]] == player) {
                cout << "Congratulations! You win!" << endl;
            } else {
                cout << "Computer wins! Better luck next time." << endl;
            }
            return true; // A winner has been found
        }
    }

    return false;
}

bool checkTie(const Board& spaces) {
    // for(int i = 0; i < 9; i++) {
    //     if(spaces[i] == ' ') {
    //         // if there is a space anywhere, the game is not a tie, continue playing
    //         return false;
    //     }
    // }
    // return true;
    // More modern way using STL algorithms
    return std::all_of(spaces.begin(), spaces.end(), [](char c) { return c != ' '; });
}

int main()
{
    Board spaces;
    spaces.fill(' ');

    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            // running = false;
            break;
        } else if(checkTie(spaces)) {
            cout << "It's a tie!" << endl;
            // running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            // running = false;
            break;
        } else if(checkTie(spaces)) {
            cout << "It's a tie!" << endl;
            // running = false;
            break;
        }
    }


    return 0;
}
