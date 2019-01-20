#include "tictactoe.hpp"

char pos[10] = {'~', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void showBoard() {
    std::cout<< "\n" << pos[1] << "|" << pos[2] << "|" << pos[3] << std::endl;
    std::cout<< pos[4] << "|" << pos[5] << "|" << pos[6] << std::endl;
    std::cout<< pos[7] << "|" << pos[8] << "|" << pos[9] << std::endl;
}
bool win() {
    if (pos[1] == pos[2] && pos[2] == pos[3]) //H1
        return 1;
    else if (pos[4] == pos[5] && pos[5] == pos[6]) //H2
        return 1;
    else if (pos[7] == pos[8] && pos[8] == pos[9]) //H3
        return 1;
    else if (pos[1] == pos[4] && pos[4] == pos[7]) //V1
        return 1;
    else if (pos[2] == pos[5] && pos[5] == pos[8]) //V2
        return 1;
    else if (pos[3] == pos[6] && pos[6] == pos[9]) //V3
        return 1;
    else if (pos[1] == pos[5] && pos[5] == pos[9]) //D1
        return 1;
    else if (pos[3] == pos[5] && pos[5] == pos[7]) //D2
        return 1;

    return 0;
}

char whoWon() {
    if (pos[1] == 'X' && pos[2] == 'X' && pos[3] == 'X') //H1
        return '1';
    else if (pos[1] == 'O' && pos[2] == 'O' && pos[3] == 'O') //H1
        return '2';
    else if (pos[4] == 'X' && pos[5] == 'X' && pos[6] == 'X') //H2
        return '1';
    else if (pos[4] == 'O' && pos[5] == 'O' && pos[6] == 'O') //H2
        return '1';
    else if (pos[7] == 'X' && pos[8] == 'X' && pos[9] == 'X') //H3
        return '1';
    else if (pos[7] == 'O' && pos[8] == 'O' && pos[9] == 'O') //H3
        return '2';
    else if (pos[1] == 'X' && pos[4] == 'X' && pos[7] == 'X') //V1
        return '1';
    else if (pos[1] == 'O' && pos[4] == 'O' && pos[7] == 'O') //V1
        return '2';
    else if (pos[2] == 'X' && pos[5] == 'X' && pos[8] == 'X') //V2
        return '1';
    else if (pos[2] == 'O' && pos[5] == 'O' && pos[8] == 'O') //V2
        return '2';
    else if (pos[3] == 'X' && pos[6] == 'X' && pos[9] == 'X') //V3
        return '1';
    else if (pos[3] == 'O' && pos[6] == 'O' && pos[9] == 'O') //V3
        return '2';
    else if (pos[1] == 'X' && pos[5] == 'X' && pos[9] == 'X') //D1
        return '1';
    else if (pos[1] == 'O' && pos[5] == 'O' && pos[9] == 'O') //D1
        return '2';
    else if (pos[3] == 'X' && pos[5] == 'X' && pos[7] == 'X') //D2
        return '1';
    else if (pos[3] == 'O' && pos[5] == 'O' && pos[7] == 'O') //D2
        return '2';

    return '\0';
}

bool isPosValid(int i) {
    if (i < 1 || i > 9) {
        std::cout << "ERROR: Valid positions for Tic Tac Toe are integers [1-9]!" << std::endl;
        return false;
    }

    if (pos[i] == 'X' || pos[i] == 'O') {
        std::cout << "ERROR: This space has been taken. Please use a different one!" << std::endl;
        return false; 
    }

    return true;
}

int main() {
    std::cout << "\033[1;35m~~~WELCOME TO TIC TAC TOE!!!~~~"<< std::endl;
    std::cout << "PLAYER 1: X \t\t PLAYER 2: O" << std::endl;
    std::cout << "\033[0m";


    bool gameOver = false;
    int moveCount = 1;
    while(!gameOver && moveCount <= 9) {
        showBoard(); 
        int p1Pos, p2Pos; //Positions players choose to mark

        // *Player 1's TURN*
        do{
        std::cout << "\n*PLAYER 1*" << std::endl;
        std::cout << "Enter a position [1-9] to place an X on: " << std::endl;
        std::cin >> p1Pos;
        } while (isPosValid(p1Pos) != true);

        pos[p1Pos] = 'X';
        moveCount++;

        if(win()) {
            showBoard();
            gameOver = 1;
            if (whoWon() == '1')
                std::cout << "\n\033[1;36mPLAYER 1 WINS!!!" << "\033[0m" << std::endl; 
            else 
                std::cout << "\n\033[1;36mPLAYER 2 WINS!!!" << "\033[0m" << std::endl;
            continue; 
        }

        if (moveCount == 9)
            break; 
        
        showBoard(); //Display an updated game board

        // *Player 2's TURN*
        do{
        std::cout << "\n*PLAYER 2*" << std::endl;
        std::cout << "Enter a position [1-9] to place an O on: " << std::endl;
        std::cin >> p2Pos;
        } while (isPosValid(p2Pos) != true);

        pos[p2Pos] = 'O';
        moveCount++;

        if(win()) {
            showBoard();
            gameOver = 1;
            if (whoWon() == '2')
                std::cout << "\n\033[1;36mPLAYER 2 WINS!!!" << "\033[0m" << std::endl;
            else 
                std::cout << "\n\033[1;36mPLAYER 1 WINS!!!" << "\033[0m" << std::endl; 
            continue; 
        }
    }

    if (whoWon() == '\0')
        std::cout << "\n\033[1;31mIT'S A DRAW!!!" << "\033[0m" << std::endl;

    return 0;
}

