#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>

class Game {
private:
    Board board;
    std::string currentPlayer;

public:
    Game() : currentPlayer("white") {
        board.initialize();
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == "white") ? "black" : "white";
    }

    void play() {
        std::string start, end;

        while (true) {
            board.display();
            std::cout << currentPlayer << "'s turn. Enter move (e.g., e2 e4): ";
            std::cin >> start >> end;

            int startX, startY, endX, endY;

            // Convertir las posiciones clásicas a índices
            if (!Board::convertPosition(start, startX, startY) || 
                !Board::convertPosition(end, endX, endY)) {
                std::cout << "Invalid input format. Try again.\n";
                continue;
            }

            // Intentar realizar el movimiento
            if (board.movePiece(startX, startY, endX, endY)) {
                std::cout << "Move successful!\n";
                switchPlayer();
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }
};

#endif
