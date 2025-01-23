#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
protected:
    std::string color; // "white" o "black"
    char symbol;       // 'P' para Peón, 'K' para Rey, etc.

public:
    Piece(std::string color, char symbol) : color(color), symbol(symbol) {}
    virtual ~Piece() = default;

    char getSymbol() const { return symbol; }
    std::string getColor() const { return color; }

    virtual bool isValidMove(int startX, int startY, int endX, int endY) const = 0;
};

class Pawn : public Piece {
public:
    Pawn(std::string color) : Piece(color, 'P') {}
    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int direction = (color == "white") ? -1 : 1;
        return (endX == startX + direction) && (endY == startY);
    }
};

#endif
