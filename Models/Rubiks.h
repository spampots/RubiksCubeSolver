//rubiks.h
#ifndef RUBIKS_H
#define RUBIKS_H

#include "iostream"
#include "string"
#include "cstdint"
#include "vector"

using namespace std;

class RubiksCube {

public:
    enum class Face {
        Up, Left, Front, Right, Back, Down
    };
    enum class Color {
        white, orange, green, red, blue, yellow
    };
    enum class Move {
        U, Up, U2,
        D, Dp, D2,
        F, Fp, F2,
        B, Bp, B2,
        L, Lp, L2, 
        R, Rp, R2
    };

    //get face coloe
    virtual Color getColor(Face face, unsigned row, unsigned col) const = 0;

    //return code for color
    static char getColorLetter(Color color);

    //is cube solved
    virtual bool isSolved() const = 0;

    //return move in string format
    static string getMove(Move ind);

    void print() const;

    vector<Move> randomShuffleCube(unsigned int times);

    RubiksCube &move(Move ind);

    RubiksCube &invert(Move ind);

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fP() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uP() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lP() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dP() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rP() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bP() = 0;

    virtual RubiksCube &b2() = 0;

    // string getCornerColorString(uint8_t ind) const;

    // uint8_t getCornerIndex(uint8_t ind) const;

    // uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif