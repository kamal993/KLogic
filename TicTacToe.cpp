#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;

class TicTacToe {
private:

    char *board;
    char player, computer;
    char playerName[30];
    char playerNameTwo[30];

    int type;
public:
    int turn;
    int repeat[9];

    TicTacToe(bool computer_plays_first, char select_player, int type) { //Constructor
        board = new char [9];
        for (int i = 0; i < 9; ++i) {
            board[i] = ' ';
        }
        player = select_player;
        strcpy(playerName, "");
        this->type = type;
        if (select_player == 'X')
            computer = 'O';
        else
            computer = 'X';
        turn = 1;
        if (type == 1)
            if (computer_plays_first)
                playComputer(); //computer plays first
    }

    void naming(char name[30], char nameTwo[30]) {
        strcpy(playerName, name);
        strcpy(playerNameTwo, nameTwo);
    }

    bool playUser(int n) { //user palys a move
        if (board[n] == ' ') {
            board[n] = player;
            turn++;
            return true;
        }
        return false;
    }

    bool playPUser(int n) { //user palys a move
        if (board[n] == ' ') {
            board[n] = computer;
            turn++;
            return true;
        }
        return false;
    }

    bool playComputer() {
        int valid, position;
        if (turn > 9)
            return false;
        do {
            position = randomPositionGenerator(9);
            valid = 1;
            if (board[position] == ' ') {
                turn++;
                board[position] = computer;
                return true;
            } else {
                valid = 0;
            }
        } while (!valid);
        return false;

    }

    int randomPositionGenerator(int n) {

        int variable, valid, k = 0;
        do {
            valid = 1;
            variable = rand() % n;
            for (int i = 0; i < k; i++)
                if (repeat[i] == variable) {
                    valid = 0;
                    break;
                }

        } while (!valid);
        repeat[k] = variable;
        return variable;
    }

    bool checkWin(char &a, char &b, char &c, char p) {
        if (a == p && a == b && a == c && b == c)
            return true;
        else
            return false;
    }

    bool whoWins() {
        int x, y, z;
        for (x = 0, y = 1, z = 2; z <= 8; x += 3, y += 3, z += 3) {
            if (checkWin(board[x], board[y], board[z], computer)) {
                if (type == 1)
                    cout << "\n\n\tComputer Wins" << endl;
                else
                    cout << "\n\n\t" << playerNameTwo << " Wins" << endl;
                return true;
            }
            if (checkWin(board[x], board[y], board[z], player)) {
                // cout << "\n\n\tPlayer Wins" << endl;
                cout << "\n\n\t" << playerName << " Wins";
                return true;
            }
        }
        for (x = 0, y = 3, z = 6; z <= 8; x += 1, y += 1, z += 1) {
            if (checkWin(board[x], board[y], board[z], computer)) {
                if (type == 1)
                    cout << "\n\n\tComputer Wins" << endl;
                else
                    cout << "\n\n\t" << playerNameTwo << " Wins" << endl;
                return true;
            }
            if (checkWin(board[x], board[y], board[z], player)) {
                //    cout << "Player Wins" << endl;
                cout << "\n\n\t" << playerName << " Wins";

                return true;
            }
        }
        x = 0;
        y = 4;
        z = 8;
        if (checkWin(board[x], board[y], board[z], computer)) {
            if (type == 1)
                cout << "\n\n\tComputer Wins" << endl;
            else
                cout << "\n\n\t" << playerNameTwo << " Wins" << endl;
            return true;
        }
        if (checkWin(board[x], board[y], board[z], player)) {
            //cout << "Player Wins" << endl;
            cout << "\n\n\t" << playerName << " Wins";

            return true;
        }
        x = 2;
        y = 4;
        z = 6;
        if (checkWin(board[x], board[y], board[z], computer)) {
            if (type == 1)
                cout << "\n\n\tComputer Wins" << endl;
            else
                cout << "\n\n\t" << playerNameTwo << " Wins" << endl;
            return true;
        }
        if (checkWin(board[x], board[y], board[z], player)) {
            //cout << "Player Wins" << endl;
            cout << "\n\n\t" << playerName << " Wins";

            return true;
        }
        return false;
    }

    bool isGameOver() {
        return turn > 9 ? true : false;
    }

    void displayBoard() {
        cout << "\n\n\t\t\t-------" << endl;
        cout << "\t\t\t|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
        cout << "\t\t\t-------" << endl;
        cout << "\t\t\t|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
        cout << "\t\t\t-------" << endl;
        cout << "\t\t\t|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl;
        cout << "\t\t\t-------" << endl;
    }

};

int menu() {
    int type, valid;

    do {
        cout << "\n\n\t 1. Player v/s Computer";
        cout << "\n\n\t 2. Player v/s Player";
        cout << "\n\n\t Select type of Game:";
        cin >> type;
        valid = 1;
        if (!(type == 1 || type == 2)) {
            valid = 0;
            cout << "\n\n\tInvalid Option. Try Again!!!";
        }
    } while (!valid);

    return type;
}

void start() {
    int type = menu();
    int choice, valid;
    char name[30], nameTwo[30] = "";
    char XO;

    do {

        if (type == 1) {
            cout << "\n\n\tWho will play first?(Computer/User): ";
            cout << "\n\n\tEnter 0 for Computer and 1 for User.:";
        } else {
            cout << "\n\n\tWho will play first?(Player 1/Player 2): ";
            cout << "\n\n\tEnter 0 for Player 1 and 1 for Player 2.:";
        }

        cin>>choice;
        valid = 1;
        if (!(choice == 0 || choice == 1)) {
            valid = 0;
            cout << endl << "\t\tInvalid Number...Try Again!!!";
        }

    } while (!valid);

    do {
        cout << "\n\n\tEnter Player name:";
        cin.ignore();
        fgets(name, 20, stdin);
        valid = 1;
        if (strlen(name) < 3) {
            valid = 0;
            cout << "\n\n\tName should be at least 3 characters long... Try Again!!! ";
        }


    } while (!valid);
    if (type == 2)
        do {
            cout << "\n\n\tEnter Player 2 name:";

            fgets(nameTwo, 20, stdin);
            valid = 1;
            if (strlen(nameTwo) < 3) {
                valid = 0;
                cout << "\n\n\tName should be at least 3 characters long... Try Again!!! ";
            }


        } while (!valid);

    if (type == 2) {

    }

    size_t ln = strlen(name) - 1;
    if (name[ln] == '\n')
        name[ln] = '\0';
    ln = strlen(nameTwo) - 1;
    if (nameTwo[ln] == '\n')
        nameTwo[ln] = '\0';

    do {
        cout << "\n\n\tSelect Player 1 character (X/O): ";
        cin>>XO;
        valid = 1;
        if (!(XO == 'X' || XO == 'O')) {
            valid = 0;
            cout << endl << "\t\tInvalid Number...Try Again!!!";
        }

    } while (!valid);
    TicTacToe ticTacToe(choice == 0 ? true : false, XO, type);
    ticTacToe.displayBoard();
    ticTacToe.naming(name, nameTwo);

    while (!ticTacToe.isGameOver() && !ticTacToe.whoWins()) {
        cout << "\n\n\tChoose the block between (1-9)";
        cout << "\n\n\tPlay your move " << name << " : ";
        cin>>choice;
        if (ticTacToe.playUser(--choice)) {
            if (type != 2) {
                if (ticTacToe.playComputer()) {
                    ticTacToe.displayBoard();
                    if (ticTacToe.turn > 9) {
                        cout << "\n\n\tGame Over, Match Draw!!!..." << endl;
                        //       break;
                    }

                }
            } else if (type == 2) {

                ticTacToe.displayBoard();
                if (ticTacToe.whoWins()) {
                    break;
                }
                do {
                    cout << "\n\n\tChoose the block between (1-9)";
                    cout << "\n\n\tPlay your move " << nameTwo << " : ";
                    cin>>choice;

                    valid = 1;

                    if (ticTacToe.playPUser(--choice)) {
                        ticTacToe.displayBoard();
                        if (ticTacToe.turn > 9) {
                            cout << "\n\n\tGame Over, Match Draw!!!..." << endl;
                            //       break;
                        }

                    } else {
                        ticTacToe.displayBoard();
                        cout << "\n\n\tInvalid Move..." << endl;
                        valid = 0;
                    }
                } while (!valid);
            }
        } else {
            ticTacToe.displayBoard();
            cout << "\n\n\tInvalid Move..." << endl;
        }

    }

}

void introduction() {

    cout << "\t\t**************************************************";
    cout << "\n\t\t*                TIC TAC TOE GAME                *";
    cout << "\n\t\t**************************************************";
    cout << "\n\n\t\t              PROGRAMMER : KAMAL SHARMA";
    cout << "\n\t\t\t    ****************************";
    cout << endl;
    system("pause");
}

int main() {
    srand(time(NULL));
    introduction();
    start();
    return 0;
}
