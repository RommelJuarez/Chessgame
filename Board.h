#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <memory>
#include <iostream>

class Board {
private:
    std::vector<std::vector<std::shared_ptr<Piece>>> grid;

public:
    Board() : grid(8, std::vector<std::shared_ptr<Piece>>(8, nullptr)) {}

    void initialize() {
        for (int i = 0; i < 8; i++) {
            grid[1][i] = std::make_shared<Pawn>("black"); // Peones negros
            grid[6][i] = std::make_shared<Pawn>("white"); // Peones blancos
        }
    }

    void display() const {
        std::cout << "  a b c d e f g h\n"; // Notación de columnas
        for (int row = 0; row < 8; ++row) {
            std::cout << (8 - row) << " "; // Notación de filas
            for (int col = 0; col < 8; ++col) {
                if (grid[row][col]) {
                    std::cout << grid[row][col]->getSymbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << (8 - row) << "\n"; // Notación de filas al final
        }
        std::cout << "  a b c d e f g h\n"; // Notación de columnas repetida
    }

    bool movePiece(int startX, int startY, int endX, int endY) {
        auto piece = grid[startX][startY];
        if (piece && piece->isValidMove(startX, startY, endX, endY)) {
            grid[endX][endY] = piece;
            grid[startX][startY] = nullptr;
            return true;
        }
        return false;
    }

    // Método para convertir coordenadas clásicas a índices
    static bool convertPosition(const std::string& pos, int& x, int& y) {
        if (pos.length() != 2) return false;
        char file = pos[0];
        char rank = pos[1];
        if (file < 'a' || file > 'h' || rank < '1' || rank > '8') return false;

        x = 8 - (rank - '0'); // Fila (inversa)
        y = file - 'a';       // Columna
        return true;
    }
};

#endif
